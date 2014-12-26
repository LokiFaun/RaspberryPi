#ifndef CONFIGURATIONWIZARDFACTORY_H__
#define CONFIGURATIONWIZARDFACTORY_H__

#pragma once

#include <QWizard>
#include <QWizardPage>

class ConfigurationWizardFactory
{
public:
    static QWizard * createConfigurationWizard(bool load = false);

private:
};

#endif // CONFIGURATIONWIZARDFACTORY_H__
