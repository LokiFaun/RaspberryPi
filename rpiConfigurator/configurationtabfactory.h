#ifndef CONFIGURATIONTABFACTORY_H__
#define CONFIGURATIONTABFACTORY_H__

#pragma once

#include "iconfigurationwidget.h"
#include "configuration.h"

class ConfigurationTabFactory
{
public:

    static IConfigurationWidget * createConfigurationTab(Configuration::ConfigurationType type, Configuration * pConfiguration);

private:
    static IConfigurationWidget * createServiceMonitorConfigurationTab(Configuration * pConfiguration);
    static IConfigurationWidget * createControllerConfiguration(Configuration * pConfiguration);
    static IConfigurationWidget * createLoggerConfiguration(Configuration * pConfiguration);
};

#endif // CONFIGURATIONTABFACTORY_H__
