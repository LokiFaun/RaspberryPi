#ifndef CONFIGURATIONTABFACTORY_H__
#define CONFIGURATIONTABFACTORY_H__

#pragma once

#include <QWidget>
#include "configuration.h"

class ConfigurationTabFactory
{
public:

    QWidget * createConfigurationTab(Configuration::ConfigurationType type, Configuration * pConfiguration);

private:
    QWidget * createServiceMonitorConfigurationTab(Configuration * pConfiguration);
    QWidget * createControllerConfiguration(Configuration * pConfiguration);
    QWidget * createLoggerConfiguration(Configuration * pConfiguration);
};

#endif // CONFIGURATIONTABFACTORY_H__
