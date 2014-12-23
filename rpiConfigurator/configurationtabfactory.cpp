#include "configurationtabfactory.h"
#include "servicemonitorconfiguration.h"
#include "servicemonitorconfigurationwidget.h"

#include <QPushButton>
#include <QLayout>
#include <QScrollArea>
#include <QDockWidget>

QWidget * ConfigurationTabFactory::createConfigurationTab(Configuration::ConfigurationType type, Configuration * pConfiguration)
{
    switch (type)
    {
    case Configuration::ServiceMonitor:
        return createServiceMonitorConfigurationTab(pConfiguration);
    case Configuration::Controller:
        return createControllerConfiguration(pConfiguration);
    case Configuration::Logger:
        return createLoggerConfiguration(pConfiguration);
    default:
        return NULL;
    }
}

QWidget * ConfigurationTabFactory::createServiceMonitorConfigurationTab(Configuration * pConfiguration)
{
    ServiceMonitorConfiguration * pMonitorConfig = dynamic_cast<ServiceMonitorConfiguration *>(pConfiguration);
    if (pMonitorConfig == NULL)
    {
        return NULL;
    }
    
    ServiceMonitorConfigurationWidget * pWidget = new ServiceMonitorConfigurationWidget(pMonitorConfig);

    QDockWidget * pDockWidget = new QDockWidget;
    pDockWidget->setAllowedAreas(Qt::BottomDockWidgetArea);
    pDockWidget->setFeatures(QDockWidget::NoDockWidgetFeatures);
    pDockWidget->layout()->setMargin(5);
    pDockWidget->layout()->setContentsMargins(5, 5, 5, 5);

    QPushButton * pAddButton = new QPushButton;
    pAddButton->setText("Add Service");
    QObject::connect(pAddButton, SIGNAL(clicked()), pWidget, SLOT(addNewService()));

    QWidget * pBottomWidget = new QWidget;
    QHBoxLayout * pLayout = new QHBoxLayout;
    pLayout->addWidget(pAddButton);
    pBottomWidget->setLayout(pLayout);

    pDockWidget->setWidget(pBottomWidget);

    pWidget->addDockWidget(Qt::BottomDockWidgetArea, pDockWidget);

    return pWidget;
}

QWidget * ConfigurationTabFactory::createControllerConfiguration(Configuration * /*pConfiguration*/)
{
    return NULL;
}

QWidget * ConfigurationTabFactory::createLoggerConfiguration(Configuration * /*pConfiguration*/)
{
    return NULL;
}
