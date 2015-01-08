#include "configurationtabfactory.h"
#include "servicemonitorconfiguration.h"
#include "servicemonitorconfigurationwidget.h"

#include <QPushButton>
#include <QLayout>
#include <QScrollArea>
#include <QDockWidget>
#include <QLabel>
#include <QLineEdit>

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

    QPushButton * pAddButton = new QPushButton("Add Service");
    QObject::connect(pAddButton, SIGNAL(clicked()), pWidget, SLOT(addNewService()));

    QPushButton * pSaveButton = new QPushButton("Save");
    QObject::connect(pSaveButton, SIGNAL(clicked()), pWidget, SLOT(saveServices()));

    QPushButton * pInstallButton = new QPushButton("Install");
    QObject::connect(pInstallButton, SIGNAL(clicked()), pWidget, SLOT(install()));

    QPushButton * pStartButton = new QPushButton("Start");
    QObject::connect(pStartButton, SIGNAL(clicked()), pWidget, SLOT(start()));

    QLineEdit * pServicePathBlock = new QLineEdit;
    QObject::connect(pServicePathBlock, SIGNAL(textEdited()), pWidget, SLOT(setServicePath()));

    QWidget * pBottomWidget = new QWidget;
    QGridLayout * pLayout = new QGridLayout;
    pLayout->setContentsMargins(5, 5, 5, 5);
    pLayout->addWidget(pAddButton, 0, 0);
    pLayout->addWidget(pSaveButton, 0, 1);
    pLayout->addWidget(new QLabel("Service:"), 2, 0);
    pLayout->addWidget(pServicePathBlock, 2, 1);
    pLayout->addWidget(pInstallButton, 3, 0);
    pLayout->addWidget(pStartButton, 3, 1);
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
