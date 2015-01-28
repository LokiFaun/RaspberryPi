#ifndef CONFIGURATIONTABFACTORY_H__
#define CONFIGURATIONTABFACTORY_H__

#pragma once

#include "iconfigurationwidget.h"
#include "configuration.h"

class ConfigurationTabFactory
{
public:

    static IConfigurationWidget * createConfigurationTab(rpi::Configuration::ConfigurationType type, rpi::Configuration * pConfiguration);

private:
    static IConfigurationWidget * createServiceMonitorConfigurationTab(rpi::Configuration * pConfiguration);
    static IConfigurationWidget * createControllerConfiguration(rpi::Configuration * pConfiguration);
    static IConfigurationWidget * createLoggerConfiguration(rpi::Configuration * pConfiguration);
};

#endif // CONFIGURATIONTABFACTORY_H__
