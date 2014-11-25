#include "logmanager.h"
#include "debugappender.h"

using namespace rpi;

LogManager::LogManager()
{
    m_pAppender = QSharedPointer<DebugAppender>::create();
}

LogManager &LogManager::getInstance()
{
    static LogManager m_Instance;
    return m_Instance;
}

RpiLogger * LogManager::getLoggerByName(const QString &name)
{
    if (m_Loggers.contains(name))
    {
        return m_Loggers[name];
    }
    m_Loggers[name] = new RpiLogger(name, this);
    m_Loggers[name]->setAppender(m_pAppender);
    return m_Loggers[name];
}

RpiLogger * LogManager::getLogger(const QString &name)
{
    return LogManager::getInstance().getLoggerByName(name);
}
