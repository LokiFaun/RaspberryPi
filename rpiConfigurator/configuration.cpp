#include "configuration.h"


Configuration::Configuration(QString const & fileName) : m_ConfigurationFile(fileName) { }


Configuration::~Configuration() { }

QString Configuration::configurationFile() const
{
    return m_ConfigurationFile;
}

void Configuration::setConfigurationFile(QString const & value)
{
    m_ConfigurationFile = value;
}

