#include "loggerconfiguration.h"

#include <QMetaEnum>

#include "../../qtjsonsettings/qtjsonsettings.h"

using namespace rpi;


LoggerConfiguration &LoggerConfiguration::getInstance()
{
    static LoggerConfiguration m_Instance;
    return m_Instance;
}

bool LoggerConfiguration::load(const QString &fileName)
{
    QtJsonSettings settings(fileName);
    QVariant type = settings.value("Logger/Type");
    if (type.isValid())
    {
        m_Type = loggerTypeFromString(type.toString());
    }
    QVariant level = settings.value("Logger/Level");
    if (level.isValid())
    {
        m_Level = logLevelFromString(level.toString());
    }
    QVariant logFileName = settings.value("Logger/Filename");
    if (logFileName.isValid())
    {
        m_FileName = logFileName.toString();
    }
    return false;
}

LoggerConfiguration::LoggerType LoggerConfiguration::getType() const
{
    return m_Type;
}

LoggerConfiguration::LogLevel LoggerConfiguration::getLevel() const
{
    return m_Level;
}

QString LoggerConfiguration::getFileName() const
{
    return m_FileName;
}

QString LoggerConfiguration::logLevelToString(LoggerConfiguration::LogLevel level)
{
    QMetaObject object = staticMetaObject;
    QMetaEnum logLevel = object.enumerator(object.indexOfEnumerator("LogLevel"));
    return logLevel.valueToKey(static_cast<int>(level));
}

LoggerConfiguration::LogLevel LoggerConfiguration::logLevelFromString(const QString &level)
{
    QMetaObject object = staticMetaObject;
    QMetaEnum logLevel = object.enumerator(object.indexOfEnumerator("LogLevel"));
    return static_cast<LogLevel>(logLevel.keyToValue(level.toStdString().c_str()));
}

QString LoggerConfiguration::loggerTypeToString(LoggerConfiguration::LoggerType type)
{
    QMetaObject object = staticMetaObject;
    QMetaEnum loggerType = object.enumerator(object.indexOfEnumerator("LoggerType"));
    return loggerType.valueToKey(static_cast<int>(type));
}

LoggerConfiguration::LoggerType LoggerConfiguration::loggerTypeFromString(const QString &type)
{
    QMetaObject object = staticMetaObject;
    QMetaEnum loggerType = object.enumerator(object.indexOfEnumerator("LoggerType"));
    return static_cast<LoggerType>(loggerType.keyToValue(type.toStdString().c_str()));
}
