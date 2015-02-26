#include "configuration.h"
#include <name_defs.h>

#include "../../qtjsonsettings/qtjsonsettings.h"

using namespace rpi;

const QString Configuration::LoggingConfigurationPath = "Logging";
const QString Configuration::LoggingFileNameConfigurationPath = "FileName";
const QString Configuration::LoggingLevelConfigurationPath = "Level";
const QString Configuration::LoggingFileSizeConfigurationPath = "FileSize";
const QString Configuration::LoggingFileCountConfigurationPath = "FileCount";

Configuration::Configuration(QString const & fileName, QObject * pParent /*= NULL*/) : QObject(pParent), m_ConfigurationFile(fileName)
{
    m_pSettings = new QtJsonSettings(fileName, this);
}

QString Configuration::loggingFilename() const
{
    m_pSettings->beginGroup(LoggingConfigurationPath);
    QString const value = m_pSettings->value(LoggingFileNameConfigurationPath, DefaultLoggingFilename).toString();
    m_pSettings->endGroup();
    return value;
}

QString Configuration::loggingLevel() const
{
    m_pSettings->beginGroup(LoggingConfigurationPath);
    QString const value = m_pSettings->value(LoggingLevelConfigurationPath, DefaultLoggingLevel).toString();
    m_pSettings->endGroup();
    return value;
}

int Configuration::loggingFileSize() const
{
    m_pSettings->beginGroup(LoggingConfigurationPath);
    int const value = m_pSettings->value(LoggingFileSizeConfigurationPath, DefaultLoggingFileSize).toInt();
    m_pSettings->endGroup();
    return value;
}

int Configuration::loggingFileCount() const
{
    m_pSettings->beginGroup(LoggingConfigurationPath);
    int const value = m_pSettings->value(LoggingFileCountConfigurationPath, DefaultLoggingFileCount).toInt();
    m_pSettings->endGroup();
    return value;
}

void Configuration::setLoggingFilename(QString const & fileName)
{
    m_pSettings->beginGroup(LoggingConfigurationPath);
    m_pSettings->setValue(LoggingFileNameConfigurationPath, fileName);
    m_pSettings->endGroup();
    emit configurationChanged();
}

void Configuration::setLoggingLevel(QString const & level)
{
    m_pSettings->beginGroup(LoggingConfigurationPath);
    m_pSettings->setValue(LoggingLevelConfigurationPath, level);
    m_pSettings->endGroup();
    emit configurationChanged();
}

void Configuration::setLoggingFileSize(int size)
{
    m_pSettings->beginGroup(LoggingConfigurationPath);
    m_pSettings->setValue(LoggingFileSizeConfigurationPath, size);
    m_pSettings->endGroup();
    emit configurationChanged();
}

void Configuration::setLoggingFileCount(int count)
{
    m_pSettings->beginGroup(LoggingConfigurationPath);
    m_pSettings->setValue(LoggingFileCountConfigurationPath, count);
    m_pSettings->endGroup();
    emit configurationChanged();
}

void Configuration::sync()
{
    m_pSettings->sync();
}

QString Configuration::configurationFile() const
{
    return m_ConfigurationFile;
}
