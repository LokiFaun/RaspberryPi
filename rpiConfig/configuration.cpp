#include "configuration.h"

using namespace rpi;

Configuration::Configuration(QString const & fileName, QObject * pParent /*= NULL*/) : QObject(pParent), m_ConfigurationFile(fileName) { }


Configuration::~Configuration() { }

QString Configuration::configurationFile() const
{
    return m_ConfigurationFile;
}

void Configuration::setConfigurationFile(QString const & value)
{
    m_ConfigurationFile = value;
}

