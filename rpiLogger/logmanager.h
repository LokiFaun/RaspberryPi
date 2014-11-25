#ifndef LOGMANAGER_H
#define LOGMANAGER_H

#include <QObject>
#include <QMap>
#include <QSharedPointer>
#include <QWeakPointer>

#include "rpilogger.h"
#include "iappender.h"
#include "loggerconfiguration.h"

namespace rpi
{

class RPILOGGERSHARED_EXPORT LogManager : public QObject
{
    Q_OBJECT

public:

    static LogManager & getInstance();
    RpiLogger * getLoggerByName(QString const & name);
    void configure(LoggerConfiguration::LogLevel level);
    static RpiLogger * getLogger(const QString &name);

private:
    LogManager();
    virtual ~LogManager() { }
    LogManager(LogManager const &);
    LogManager & operator = (LogManager const &);

private:
    QMap<QString, RpiLogger *> m_Loggers;
    QSharedPointer<IAppender> m_pAppender;

};

#define RPI_DEBUG(logger, message) \
    LogManager::getLogger(logger)->debug(__FILE__, __LINE__, Q_FUNC_INFO, message)

#define RPI_INFO(logger, message) \
    LogManager::getLogger(logger)->info(__FILE__, __LINE__, Q_FUNC_INFO, message)

#define RPI_WARN(logger, message) \
    LogManager::getLogger(logger)->warning(__FILE__, __LINE__, Q_FUNC_INFO, message)

#define RPI_ERROR(logger, message) \
    LogManager::getLogger(logger)->error(__FILE__, __LINE__, Q_FUNC_INFO, message)

#define RPI_FATAL(logger, message) \
    LogManager::getLogger(logger)->fatal(__FILE__, __LINE__, Q_FUNC_INFO, message)

}

#endif // LOGMANAGER_H
