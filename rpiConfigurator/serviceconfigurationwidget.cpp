#include "serviceconfigurationwidget.h"

#include <QGroupBox>
#include <QGridLayout>
#include <QLabel>

ServiceConfigurationWidget::ServiceConfigurationWidget(int nr)
{
    m_pIdBlock = new QLineEdit;
    m_pNameBlock = new QLineEdit;
    m_pTimeoutBlock = new QLineEdit;
    m_pRemoveButton = new QPushButton("Remove");

    QGroupBox *groupBox = new QGroupBox(QString("Service: %1").arg(nr));
    groupBox->setMinimumHeight(125);
    groupBox->setMinimumWidth(200);

    QGridLayout * pLayout = new QGridLayout;
    pLayout->addWidget(new QLabel("ID:"), 0, 0);
    pLayout->addWidget(m_pIdBlock, 0, 1);
    pLayout->addWidget(new QLabel("Name:"), 1, 0);
    pLayout->addWidget(m_pNameBlock, 1, 1);
    pLayout->addWidget(new QLabel("Timeout:"), 2, 0);
    pLayout->addWidget(m_pTimeoutBlock, 2, 1);
    pLayout->addWidget(m_pRemoveButton, 3, 1);
    groupBox->setLayout(pLayout);

    QVBoxLayout * pGroupLayout = new QVBoxLayout;
    pGroupLayout->addWidget(groupBox);
    setLayout(pGroupLayout);

    connect(m_pRemoveButton, SIGNAL(clicked()), this, SLOT(removeService()));
    connect(m_pIdBlock, SIGNAL(textEdited(QString const &)), this, SLOT(onIdInputChanged(QString const &)));
    connect(m_pNameBlock, SIGNAL(textEdited(QString const &)), this, SLOT(onNameInputChanged(QString const &)));
    connect(m_pTimeoutBlock, SIGNAL(textEdited(QString const &)), this, SLOT(onTimeoutInputChanged(QString const &)));
}


ServiceConfigurationWidget::~ServiceConfigurationWidget() { }

void ServiceConfigurationWidget::removeService()
{
    emit removed(this);
}

void ServiceConfigurationWidget::onIdInputChanged(QString const & newValue)
{
    bool inputOk = false;
    const int id = newValue.toInt(&inputOk);
    if (inputOk)
    {
        emit idChanged(this, id);
    }
}

void ServiceConfigurationWidget::onNameInputChanged(QString const & newValue)
{
    emit nameChanged(this, newValue);
}

void ServiceConfigurationWidget::onTimeoutInputChanged(QString const & newValue)
{
    bool inputOk = false;
    const unsigned int timeout = newValue.toUInt(&inputOk);
    if (inputOk)
    {
        emit timeoutChanged(this, timeout);
    }
}
