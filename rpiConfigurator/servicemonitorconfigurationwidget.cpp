#include "servicemonitorconfigurationwidget.h"

#include <QScrollArea>
#include <QGroupBox>
#include <QRadioButton>
#include <QVBoxLayout>

ServiceMonitorConfigurationWidget::ServiceMonitorConfigurationWidget(ServiceMonitorConfiguration * config)
    : m_pConfiguration(config)
{
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

ServiceMonitorConfigurationWidget::~ServiceMonitorConfigurationWidget() { }

void ServiceMonitorConfigurationWidget::addNewService()
{
    ServiceConfigurationWidget * pConfig = new ServiceConfigurationWidget(m_pConfiguration->count());
    connect(pConfig,  SIGNAL(removed(QWidget *)), this, SLOT(removeService(QWidget *)));
    
    m_ServiceConfigurations.push_back(pConfig);
    m_pLayout->addWidget(pConfig);
}

void ServiceMonitorConfigurationWidget::saveConfiguration()
{
    if (m_pConfiguration != NULL)
    {
        m_pConfiguration->save();
    }
}

void ServiceMonitorConfigurationWidget::loadConfiguration()
{
    
}

void ServiceMonitorConfigurationWidget::removeService(QWidget * pWidget)
{
    m_pLayout->removeWidget(pWidget);
    delete pWidget;
    pWidget = NULL;
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
