#ifndef CONFIGURATIONWIZARDFACTORY_H__
#define CONFIGURATIONWIZARDFACTORY_H__

#pragma once

#include <QWizard>

class ConfigurationWizardFactory
{
public:
    static QWizard * createConfigurationWizard(bool load = false);
};

#endif // CONFIGURATIONWIZARDFACTORY_H__
