#include "serviceconfigurationwidget.h"
#include "logmanager.h"

#include <QGroupBox>
#include <QGridLayout>
#include <QLabel>

using namespace rpi;

ServiceConfigurationWidget::ServiceConfigurationWidget(int nr)
{
    m_Number = nr;
    m_pIdBlock = new QLineEdit;
    m_pNameBlock = new QLineEdit;
    m_pTimeoutBlock = new QLineEdit;
    m_pConfigBlock = new QLineEdit;
    m_pRemoveButton = new QPushButton("Remove");

    QGroupBox *groupBox = new QGroupBox(QString("Service: %1").arg(nr));
    groupBox->setMinimumHeight(150);
    groupBox->setMinimumWidth(200);

    QGridLayout * pLayout = new QGridLayout;
    pLayout->addWidget(new QLabel("ID:"), 0, 0);
    pLayout->addWidget(m_pIdBlock, 0, 1);
    pLayout->addWidget(new QLabel("Name:"), 1, 0);
    pLayout->addWidget(m_pNameBlock, 1, 1);
    pLayout->addWidget(new QLabel("Timeout:"), 2, 0);
    pLayout->addWidget(m_pTimeoutBlock, 2, 1);
    pLayout->addWidget(new QLabel("Config"), 3, 0);
    pLayout->addWidget(m_pConfigBlock, 3, 1);
    pLayout->addWidget(m_pRemoveButton, 4, 1);
    groupBox->setLayout(pLayout);

    QVBoxLayout * pGroupLayout = new QVBoxLayout;
    pGroupLayout->addWidget(groupBox);
    setLayout(pGroupLayout);

    connect(m_pRemoveButton, SIGNAL(clicked()), this, SLOT(removeService()));
    connect(m_pIdBlock, SIGNAL(textEdited(QString const &)), this, SLOT(onIdInputChanged(QString const &)));
    connect(m_pNameBlock, SIGNAL(textEdited(QString const &)), this, SLOT(onNameInputChanged(QString const &)));
    connect(m_pTimeoutBlock, SIGNAL(textEdited(QString const &)), this, SLOT(onTimeoutInputChanged(QString const &)));
    connect(m_pConfigBlock, SIGNAL(textEdited(QString const &)), this, SLOT(onConfigInputChanged(QString const &)));
}


ServiceConfigurationWidget::~ServiceConfigurationWidget() { }

void ServiceConfigurationWidget::removeService()
{
    RPI_DEBUG("rpiConfigurator", "emit removed");
    emit removed(this, m_Number);
}

void ServiceConfigurationWidget::onIdInputChanged(QString const & newValue)
{
    bool inputOk = false;
    const int id = newValue.toInt(&inputOk);
    if (inputOk)
    {
        RPI_DEBUG("rpiConfigurator", "emit idChanged");
        emit idChanged(m_Number, id);
    }
}

void ServiceConfigurationWidget::onNameInputChanged(QString const & newValue)
{
    RPI_DEBUG("rpiConfigurator", "emit nameChanged");
    emit nameChanged(m_Number, newValue);
}

void ServiceConfigurationWidget::onConfigInputChanged(QString const & newValue)
{
    RPI_DEBUG("rpiConfigurator", "emit configChanged");
    emit configChanged(m_Number, newValue);
}

void ServiceConfigurationWidget::onTimeoutInputChanged(QString const & newValue)
{
    bool inputOk = false;
    const unsigned int timeout = newValue.toUInt(&inputOk);
    if (inputOk)
    {
        RPI_DEBUG("rpiConfigurator", "emit timeoutChanged");
        emit timeoutChanged(m_Number, timeout);
    }
}

void ServiceConfigurationWidget::setConfiguration(int id, QString const & name, unsigned int timeout, QString const & config)
{
    m_pIdBlock->setText(QString::number(id));
    m_pNameBlock->setText(name);
    m_pTimeoutBlock->setText(QString::number(timeout));
    m_pConfigBlock->setText(config);
}
