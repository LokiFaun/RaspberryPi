#include "rpilogger.h"

#include <QDateTime>
#include <QString>
#include <QMetaEnum>
#include <QDebug>

using namespace rpi;

RpiLogger::RpiLogger(QString const & name, QObject * pParent) : QObject(pParent), m_Name(name) { }

RpiLogger::~RpiLogger() { }

void RpiLogger::setAppender(QSharedPointer<IAppender> pAppender)
{
    m_pAppender = pAppender;
}

void RpiLogger::debug(const QString &file, unsigned int line, const QString &function, const QString &message)
{
    write(LogLevel::Debug, file, line, function, message);
}

void RpiLogger::info(const QString &file, unsigned int line, const QString &function, const QString &message)
{
    write(LogLevel::Info, file, line, function, message);
}

void RpiLogger::warning(const QString &file, unsigned int line, const QString &function, const QString &message)
{
    write(LogLevel::Warning, file, line, function, message);
}

void RpiLogger::error(const QString &file, unsigned int line, const QString &function, const QString &message)
{
    write(LogLevel::Error, file, line, function, message);
}

void RpiLogger::fatal(const QString &file, unsigned int line, const QString &function, const QString &message)
{
    write(LogLevel::Fatal, file, line, function, message);
}

void RpiLogger::write(RpiLogger::LogLevel level, const QString &file, unsigned int line, const QString &function, const QString &message)
{
    QString logMessage = QString("%s [%s] %s::%s: %s (%s:%i)")
            .arg(QDateTime::currentDateTime().toString())
            .arg(logLevelToString(level))
            .arg(m_Name)
            .arg(function)
            .arg(message)
            .arg(file)
            .arg(QString::number(line));
    Q_ASSERT(!m_pAppender.isNull());
    if (!m_pAppender.isNull())
    {
        m_pAppender->write(logMessage);
    }
}

QString RpiLogger::logLevelToString(RpiLogger::LogLevel level)
{
    QMetaObject object = staticMetaObject;
    QMetaEnum logLevel = object.enumerator(object.indexOfEnumerator("LogLevel"));
    return logLevel.valueToKey(static_cast<int>(level));
}
