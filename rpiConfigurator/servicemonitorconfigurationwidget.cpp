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

    qDebug("setting up scroll area");
    QWidget * pCentralWidget = new QWidget;
    pCentralWidget->setLayout(m_pLayout);

    QScrollArea * pScrollArea = new QScrollArea;
    pScrollArea->setContentsMargins(5, 5, 5, 5);
    pScrollArea->setWidgetResizable(false);
    pScrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    pScrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    pScrollArea->setWidget(pCentralWidget);

    qDebug("setting central widget");
    setCentralWidget(pScrollArea);
}

ServiceMonitorConfigurationWidget::~ServiceMonitorConfigurationWidget() { }

void ServiceMonitorConfigurationWidget::addNewService()
{
    qDebug("adding a new service");
    
    QGroupBox *groupBox = new QGroupBox(tr("Exclusive Radio Buttons"));
    groupBox->setMinimumHeight(100);

    QVBoxLayout *vbox = new QVBoxLayout;
    groupBox->setLayout(vbox);

    m_pLayout->addWidget(groupBox);
}

void ServiceMonitorConfigurationWidget::saveConfiguration()
{
    qDebug("saving the current service");
    if (m_pConfiguration != NULL)
    {
        m_pConfiguration->save();
    }
}
