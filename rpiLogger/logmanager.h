#ifndef LOGMANAGER_H
#define LOGMANAGER_H

#pragma once

#include <QObject>
#include <QMap>
#include <QSharedPointer>

#include "rpilogger.h"

namespace rpi
{

class RPILOGGERSHARED_EXPORT LogManager : public QObject
{
    Q_OBJECT

public:

    static LogManager & instance();
    RpiLogger * logger(QString const & name);
    void configure(QString const & fileName, QString const & level, int maxFileSize, int maxFileCount);

private:
    LogManager();
    virtual ~LogManager();
    LogManager(LogManager const &);
    LogManager & operator = (LogManager const &);

private:
    QMap<QString, RpiLogger *> m_Loggers;

};

#define RPI_DEBUG(name, message) \
    LogManager::instance().logger(name)->debug(__FILE__, __LINE__, Q_FUNC_INFO, message)

#define RPI_INFO(name, message) \
    LogManager::instance().logger(name)->info(__FILE__, __LINE__, Q_FUNC_INFO, message)

#define RPI_WARN(name, message) \
    LogManager::instance().logger(name)->warning(__FILE__, __LINE__, Q_FUNC_INFO, message)

#define RPI_ERROR(name, message) \
    LogManager::instance().logger(name)->error(__FILE__, __LINE__, Q_FUNC_INFO, message)

#define RPI_FATAL(name, message) \
    LogManager::instance().logger(name)->fatal(__FILE__, __LINE__, Q_FUNC_INFO, message)

}

#endif // LOGMANAGER_H
