#ifndef LOGGERCONFIGURATION_H
#define LOGGERCONFIGURATION_H

#include <QObject>

namespace rpi
{

class LoggerConfiguration : public QObject
{
    Q_OBJECT
    Q_ENUMS(LogLevel)
    Q_ENUMS(LoggerType)

public:

    enum LogLevel
    {
        Debug = 0,
        Info = 1,
        Warning = 2,
        Error = 3,
        Fatal = 4
    };

    enum LoggerType
    {
        DebugOutput,
        File,
        Sql,
        Console
    };

    static LoggerConfiguration & getInstance();

    bool load(QString const & fileName);

    LoggerType getType() const;
    LogLevel getLevel() const;
    QString getFileName() const;

    static QString logLevelToString(LogLevel level);
    static LogLevel logLevelFromString(QString const & level);

    static QString loggerTypeToString(LoggerType type);
    static LoggerType loggerTypeFromString(QString const & type);

private:
    LoggerConfiguration() { }
    virtual ~LoggerConfiguration() { }
    LoggerConfiguration(LoggerConfiguration const &);
    LoggerConfiguration & operator = (LoggerConfiguration const &);

    LoggerType m_Type;
    LogLevel m_Level;
    QString m_FileName;
};

}

#endif // LOGGERCONFIGURATION_H
