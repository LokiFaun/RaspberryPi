#include "configurationtabfactory.h"
#include "servicemonitorconfiguration.h"
#include "servicemonitorconfigurationwidget.h"

#include <QPushButton>
#include <QLayout>
#include <QScrollArea>
#include <QDockWidget>

IConfigurationWidget * ConfigurationTabFactory::createConfigurationTab(Configuration::ConfigurationType type, Configuration * pConfiguration)
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

IConfigurationWidget * ConfigurationTabFactory::createServiceMonitorConfigurationTab(Configuration * pConfiguration)
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

    QPushButton * pAddButton = new QPushButton;
    pAddButton->setText("Add Service");
    QObject::connect(pAddButton, SIGNAL(clicked()), pWidget, SLOT(addNewService()));

    QPushButton * pSaveButton = new QPushButton;
    pSaveButton->setText("Save");
    QObject::connect(pSaveButton, SIGNAL(clicked()), pWidget, SLOT(saveServices()));

    QWidget * pBottomWidget = new QWidget;
    QHBoxLayout * pLayout = new QHBoxLayout;
    pLayout->setContentsMargins(5, 5, 5, 5);
    pLayout->addWidget(pAddButton);
    pLayout->addWidget(pSaveButton);
    pBottomWidget->setLayout(pLayout);

    pDockWidget->setWidget(pBottomWidget);

    pWidget->addDockWidget(Qt::BottomDockWidgetArea, pDockWidget);
    pWidget->loadConfiguration();

    return pWidget;
}

IConfigurationWidget * ConfigurationTabFactory::createControllerConfiguration(Configuration * /*pConfiguration*/)
{
    return NULL;
}

IConfigurationWidget * ConfigurationTabFactory::createLoggerConfiguration(Configuration * /*pConfiguration*/)
{
    return NULL;
}
