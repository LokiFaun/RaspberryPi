#include "rpilogger.h"

#include <QDateTime>

#include "loggerconfiguration.h"

using namespace rpi;

RpiLogger::RpiLogger() : QObject(NULL), m_Name("") { }

RpiLogger::RpiLogger(QString const & name, QObject * pParent) : QObject(pParent), m_Name(name) { }

RpiLogger::~RpiLogger() { }

void RpiLogger::setAppender(QSharedPointer<IAppender> pAppender)
{
    m_pAppender = pAppender;
}

void RpiLogger::debug(const QString &file, unsigned int line, const QString &function, const QString &message)
{
    write(LoggerConfiguration::Debug, file, line, function, message);
}

void RpiLogger::info(const QString &file, unsigned int line, const QString &function, const QString &message)
{
    write(LoggerConfiguration::Info, file, line, function, message);
}

void RpiLogger::warning(const QString &file, unsigned int line, const QString &function, const QString &message)
{
    write(LoggerConfiguration::Warning, file, line, function, message);
}

void RpiLogger::error(const QString &file, unsigned int line, const QString &function, const QString &message)
{
    write(LoggerConfiguration::Error, file, line, function, message);
}

void RpiLogger::fatal(const QString &file, unsigned int line, const QString &function, const QString &message)
{
    write(LoggerConfiguration::Fatal, file, line, function, message);
}

bool RpiLogger::isLevelEnabled(LoggerConfiguration::LogLevel level) const
{
    const int configuredLevel = LoggerConfiguration::instance().level();
    const int writeLevel = level;

    return writeLevel >= configuredLevel;
}

void RpiLogger::write(LoggerConfiguration::LogLevel level, const QString &file, unsigned int line, const QString &function, const QString &message)
{
    QMutexLocker lock(&m_LockObject);
    if (!isLevelEnabled(level))
    {
        return;
    }
    QString logMessage = QString("%1 [%2] %3::%4: %5 (%6:%7)").arg(
                QDateTime::currentDateTime().toString(),
                LoggerConfiguration::logLevelToString(level),
                m_Name,
                function,
                message,
                file,
                QString::number(line));
    Q_ASSERT(!m_pAppender.isNull());
    if (!m_pAppender.isNull())
    {
        m_pAppender->write(logMessage);
    }
}
