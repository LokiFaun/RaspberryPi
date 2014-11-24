#ifndef RPILOGGER_H
#define RPILOGGER_H

#include "rpilogger_global.h"

#include <QObject>
#include <QMap>
#include <QSharedPointer>

#include "iappender.h"

namespace rpi
{

class RPILOGGERSHARED_EXPORT RpiLogger : public QObject
{
    Q_OBJECT
    Q_ENUMS(LogLevel)

public:
    explicit RpiLogger(QString const & name, QObject * pParent = 0);
    virtual ~RpiLogger();

    enum class LogLevel
    {
        Debug,
        Info,
        Warning,
        Error,
        Fatal
    };

    void setAppender(QSharedPointer<IAppender> pAppender);

    void debug(QString const & file, unsigned int line, QString const & function, QString const & message);
    void info(QString const & file, unsigned int line, QString const & function, QString const & message);
    void warning(QString const & file, unsigned int line, QString const & function, QString const & message);
    void error(QString const & file, unsigned int line, QString const & function, QString const & message);
    void fatal(QString const & file, unsigned int line, QString const & function, QString const & message);

    static QString logLevelToString(LogLevel level);

private:
    void write(LogLevel level, QString const & file, unsigned int line, QString const & function, QString const & message);

    QSharedPointer<IAppender> m_pAppender;
    QString m_Name;
};

}

#endif // RPILOGGER_H
