#include "debugappender.h"

#include <QDebug>

#include "loggerconfiguration.h"

using namespace rpi;

DebugAppender::DebugAppender(QObject *parent) : QObject(parent)
{

}

void DebugAppender::write(const QString &message)
{
    if (message.contains(QString("[%1]").arg(LoggerConfiguration::logLevelToString(LoggerConfiguration::Debug))))
    {
        qDebug() << message;
    }
    else if (message.contains(QString("[%1]").arg(LoggerConfiguration::logLevelToString(LoggerConfiguration::Warning))))
    {
        qWarning() << message;
    }
    else if (message.contains(QString("[%1]").arg(LoggerConfiguration::logLevelToString(LoggerConfiguration::Info))))
    {
        qDebug() << message;
    }
    else if (message.contains(QString("[%1]").arg(LoggerConfiguration::logLevelToString(LoggerConfiguration::Error))))
    {
        qCritical() << message;
    }
    else if (message.contains(QString("[%1]").arg(LoggerConfiguration::logLevelToString(LoggerConfiguration::Fatal))))
    {
        qFatal(qPrintable(message));
    }
}
