#include "servicemonitorconfigurationwidget.h"
#include "exception.h"
#include "logmanager.h"
#include "serviceconfigurationwidget.h"

#include <QScrollArea>

using namespace rpi;

ServiceMonitorConfigurationWidget::ServiceMonitorConfigurationWidget(ServiceMonitorConfiguration * config)
    : m_pConfiguration(config)
{
    Q_ASSERT_X(m_pConfiguration != NULL, Q_FUNC_INFO, "invalid configuration");
    if (m_pConfiguration == NULL)
    {
        THROW_EXCEPTION_DETAILED("invalid configuration");
    }

    m_pConfiguration->setParent(this);

    m_pLayout = new QVBoxLayout;
    m_pLayout->setContentsMargins(5, 5, 5, 5);
    m_pLayout->setMargin(5);
    m_pLayout->setSizeConstraint(QLayout::SetMinimumSize);

    QWidget * pCentralWidget = new QWidget;
    pCentralWidget->setLayout(m_pLayout);

    QScrollArea * pScrollArea = new QScrollArea;
    pScrollArea->setContentsMargins(5, 5, 5, 5);
    pScrollArea->setWidgetResizable(false);
    pScrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    pScrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    pScrollArea->setWidget(pCentralWidget);

    setCentralWidget(pScrollArea);
}

ServiceMonitorConfigurationWidget::~ServiceMonitorConfigurationWidget()
{
}

void ServiceMonitorConfigurationWidget::addNewService()
{
    ServiceConfigurationWidget * pConfigWidget = new ServiceConfigurationWidget(m_pConfiguration->count());
    connect(pConfigWidget, SIGNAL(removed(QWidget *, int)), this, SLOT(removeService(QWidget *, int)));
    connect(pConfigWidget, SIGNAL(idChanged(int, int)), this, SLOT(changeServiceId(int, int)));
    connect(pConfigWidget, SIGNAL(nameChanged(int, QString const &)), this, SLOT(changeServiceName(int, QString const &)));
    connect(pConfigWidget, SIGNAL(timeoutChanged(int, unsigned int)), this, SLOT(changeServiceTimeout(int, unsigned int)));
    connect(pConfigWidget, SIGNAL(configChanged(int, unsigned int)), this, SLOT(changeServiceConfig(int, QString const &)));

    int const count = m_pConfiguration->count();
    m_pConfiguration->setId(count, INT_MAX);
    m_pConfiguration->setName(count, "newService");
    m_pConfiguration->setTimeout(count, UINT_MAX);
    m_pConfiguration->setConfig(count, "config.json");

    RPI_DEBUG("rpiConfigurator", QString("new number of services: %1").arg(m_pConfiguration->count()));
    pConfigWidget->setConfiguration(INT_MAX, "newService", UINT_MAX, "config.json");
    m_pLayout->addWidget(pConfigWidget);

    emit configurationChanged();
}

void ServiceMonitorConfigurationWidget::saveConfiguration()
{
    Q_ASSERT_X(m_pConfiguration != NULL, Q_FUNC_INFO, "invalid configuration");
    if (m_pConfiguration != NULL)
    {
        RPI_DEBUG("rpiConfigurator", "saving service monitor configuration");
        m_pConfiguration->sync();
    }
}

void ServiceMonitorConfigurationWidget::loadConfiguration()
{
    RPI_DEBUG("rpiConfigurator", "loading service monitor configuration");
    const int count = m_pConfiguration->count();
    for (int i = 0; i < count; i++)
    {
        ServiceConfigurationWidget * pConfigWidget = new ServiceConfigurationWidget(i);
        connect(pConfigWidget, SIGNAL(removed(QWidget *, int)), this, SLOT(removeService(QWidget *, int)));
        connect(pConfigWidget, SIGNAL(idChanged(int, int)), this, SLOT(changeServiceId(int, int)));
        connect(pConfigWidget, SIGNAL(nameChanged(int, QString const &)), this, SLOT(changeServiceName(int, QString const &)));
        connect(pConfigWidget, SIGNAL(timeoutChanged(int, unsigned int)), this, SLOT(changeServiceTimeout(int, unsigned int)));

        RPI_DEBUG("rpiConfigurator", QString("loading service id: %1").arg(m_pConfiguration->id(i)));
        RPI_DEBUG("rpiConfigurator", QString("loading service name: %1").arg(m_pConfiguration->name(i)));
        RPI_DEBUG("rpiConfigurator", QString("loading service timeout: %1").arg(m_pConfiguration->timeout(i)));
        pConfigWidget->setConfiguration(m_pConfiguration->id(i), m_pConfiguration->name(i), m_pConfiguration->timeout(i), m_pConfiguration->config(i));
        m_pLayout->addWidget(pConfigWidget);
    }
}

void ServiceMonitorConfigurationWidget::removeService(QWidget * pWidget, int nr)
{
    Q_ASSERT_X(m_pConfiguration != NULL, Q_FUNC_INFO, "invalid configuration");
    RPI_DEBUG("rpiConfigurator", "removing service");

    m_pConfiguration->remove(nr);

    m_pLayout->removeWidget(pWidget);
    delete pWidget;

    emit configurationChanged();
}

void ServiceMonitorConfigurationWidget::clearConfigurations()
{
    QLayoutItem * pItem;
    while ((pItem = m_pLayout->takeAt(0)) != NULL)
    {
        delete pItem;
        pItem = NULL;
    }
}

void ServiceMonitorConfigurationWidget::changeServiceId(int nr, int id)
{
    Q_ASSERT_X(m_pConfiguration != NULL, Q_FUNC_INFO, "invalid configuration");
    RPI_DEBUG("rpiConfigurator", QString("changing service#%1 id").arg(nr));
    if (m_pConfiguration != NULL)
    {
        m_pConfiguration->setId(nr, id);

        emit configurationChanged();
    }
}

void ServiceMonitorConfigurationWidget::changeServiceName(int nr, QString const & name)
{
    Q_ASSERT_X(m_pConfiguration != NULL, Q_FUNC_INFO, "invalid configuration");
    RPI_DEBUG("rpiConfigurator", QString("changing service#%1 name").arg(nr));
    if (m_pConfiguration != NULL)
    {
        m_pConfiguration->setName(nr, name);

        emit configurationChanged();
    }
}

void ServiceMonitorConfigurationWidget::changeServiceTimeout(int nr, unsigned int timeout)
{
    Q_ASSERT_X(m_pConfiguration != NULL, Q_FUNC_INFO, "invalid configuration");
    RPI_DEBUG("rpiConfigurator", QString("changing service#%1 timeout").arg(nr));
    if (m_pConfiguration != NULL)
    {
        m_pConfiguration->setTimeout(nr, timeout);

        emit configurationChanged();
    }
}

void ServiceMonitorConfigurationWidget::changeServiceConfig(int nr, QString const & config)
{
    Q_ASSERT_X(m_pConfiguration != NULL, Q_FUNC_INFO, "invalid configuration");
    RPI_DEBUG("rpiConfigurator", QString("changing service#%1 config").arg(nr));
    if (m_pConfiguration != NULL)
    {
        m_pConfiguration->setConfig(nr, config);

        emit configurationChanged();
    }
}

void ServiceMonitorConfigurationWidget::saveServices()
{
    saveConfiguration();

    emit configurationSaved();
}
