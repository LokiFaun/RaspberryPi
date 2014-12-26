#ifndef CONFIGURATIONTABFACTORY_H__
#define CONFIGURATIONTABFACTORY_H__

#pragma once

#include "iconfigurationwidget.h"
#include "configuration.h"

class ConfigurationTabFactory
{
public:

    IConfigurationWidget * createConfigurationTab(Configuration::ConfigurationType type, Configuration * pConfiguration);

private:
    IConfigurationWidget * createServiceMonitorConfigurationTab(Configuration * pConfiguration);
    IConfigurationWidget * createControllerConfiguration(Configuration * pConfiguration);
    IConfigurationWidget * createLoggerConfiguration(Configuration * pConfiguration);
};

#endif // CONFIGURATIONTABFACTORY_H__
