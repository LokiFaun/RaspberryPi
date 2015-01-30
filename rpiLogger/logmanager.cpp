#include "logmanager.h"
#include "QsLog.h"
#include "QsLogDest.h"
#include "exception.h"

using namespace rpi;

static QsLogging::Level parseLevel(QString const& level)
{
    if (level.compare("debug") == 0)
    {
        return QsLogging::DebugLevel;
    }
    else if (level.compare("trace") == 0)
    {
        return QsLogging::TraceLevel;
    }
    else if (level.compare("info") == 0)
    {
        return QsLogging::InfoLevel;
    }
    else if (level.compare("warning") == 0)
    {
        return QsLogging::WarnLevel;
    }
    else if (level.compare("error") == 0)
    {
        return QsLogging::DebugLevel;
    }
    else if (level.compare("fatal") == 0)
    {
        return QsLogging::FatalLevel;
    }
    else
    {
        THROW_EXCEPTION_DETAILED("bad log level");
    }
}

LogManager::LogManager()
{
    QsLogging::Logger & logger = QsLogging::Logger::instance();
    logger.setLoggingLevel(QsLogging::DebugLevel);

    QsLogging::DestinationPtr debugDestination(QsLogging::DestinationFactory::MakeDebugOutputDestination());
    logger.addDestination(debugDestination);
}

LogManager::~LogManager()
{
    QsLogging::Logger::destroyInstance();
}

LogManager &LogManager::instance()
{
    static LogManager m_Instance;
    return m_Instance;
}

RpiLogger * LogManager::logger(const QString &name)
{
    if (m_Loggers.contains(name))
    {
        return m_Loggers[name];
    }
    m_Loggers[name] = new RpiLogger(name, this);
    return m_Loggers[name];
}

void LogManager::configure(QString const& fileName, QString const& level, int maxFileSize, int maxFileCount)
{
    QsLogging::Logger & logger = QsLogging::Logger::instance();

    QsLogging::DestinationPtr fileDestination;
    if ((maxFileSize != 0) && (maxFileCount != 0))
    {
        fileDestination = QsLogging::DestinationFactory::MakeFileDestination(
            fileName, QsLogging::EnableLogRotation, QsLogging::MaxSizeBytes(maxFileSize), QsLogging::MaxOldLogCount(maxFileCount));
    }
    else if (maxFileCount != 0)
    {
        fileDestination = QsLogging::DestinationFactory::MakeFileDestination(fileName, QsLogging::EnableLogRotation, QsLogging::MaxSizeBytes(maxFileSize));
    }
    else
    {
        fileDestination = QsLogging::DestinationFactory::MakeFileDestination(fileName);
    }
    logger.addDestination(fileDestination);

    try
    {
        QsLogging::Level newLevel = parseLevel(level);
        logger.setLoggingLevel(newLevel);
    }
    catch (Exception const & ex)
    {
        QLOG_WARN() << ex.what();
    }
}