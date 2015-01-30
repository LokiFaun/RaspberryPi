#include "rpilogger.h"
#include "QsLog.h"

#include <QDateTime>

using namespace rpi;

static const QString fmtDateTime("yyyy-MM-ddThh:mm:ss.zzz");

RpiLogger::RpiLogger() : QObject(NULL), m_Name("") { }

RpiLogger::RpiLogger(QString const & name, QObject * pParent) : QObject(pParent), m_Name(name) { }

RpiLogger::~RpiLogger() { }

void RpiLogger::debug(const QString &file, unsigned int line, const QString &function, const QString &message)
{
    QLOG_DEBUG() << QString("%1 %2::%3: %4 (%5:%6)").arg(
        QDateTime::currentDateTime().toString(fmtDateTime),
        m_Name,
        function,
        message,
        file,
        QString::number(line));
}

void RpiLogger::trace(QString const& file, unsigned line, QString const& function, QString const& message)
{
    QLOG_TRACE() << QString("%1 %2::%3: %4 (%5:%6)").arg(
        QDateTime::currentDateTime().toString(fmtDateTime),
        m_Name,
        function,
        message,
        file,
        QString::number(line));
}

void RpiLogger::info(const QString &file, unsigned int line, const QString &function, const QString &message)
{
    QLOG_INFO() << QString("%1 %2::%3: %4 (%5:%6)").arg(
        QDateTime::currentDateTime().toString(fmtDateTime),
        m_Name,
        function,
        message,
        file,
        QString::number(line));
}

void RpiLogger::warning(const QString &file, unsigned int line, const QString &function, const QString &message)
{
    QLOG_WARN() << QString("%1 %2::%3: %4 (%5:%6)").arg(
        QDateTime::currentDateTime().toString(fmtDateTime),
        m_Name,
        function,
        message,
        file,
        QString::number(line));
}

void RpiLogger::error(const QString &file, unsigned int line, const QString &function, const QString &message)
{
    QLOG_ERROR() << QString("%1 %2::%3: %4 (%5:%6)").arg(
        QDateTime::currentDateTime().toString(fmtDateTime),
        m_Name,
        function,
        message,
        file,
        QString::number(line));
}

void RpiLogger::fatal(const QString &file, unsigned int line, const QString &function, const QString &message)
{
    QLOG_FATAL() << QString("%1 %2::%3: %4 (%5:%6)").arg(
        QDateTime::currentDateTime().toString(fmtDateTime),
        m_Name,
        function,
        message,
        file,
        QString::number(line));
}

