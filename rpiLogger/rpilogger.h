#ifndef RPILOGGER_H
#define RPILOGGER_H

#include "rpilogger_global.h"

#include <QObject>
#include <QMap>
#include <QSharedPointer>

#include "iappender.h"
#include "loggerconfiguration.h"

namespace rpi
{

class RPILOGGERSHARED_EXPORT RpiLogger : public QObject
{
    Q_OBJECT

public:
    explicit RpiLogger();
    explicit RpiLogger(QString const & name, QObject * pParent = 0);
    virtual ~RpiLogger();

    void setAppender(QSharedPointer<IAppender> pAppender);

    void debug(QString const & file, unsigned int line, QString const & function, QString const & message);
    void info(QString const & file, unsigned int line, QString const & function, QString const & message);
    void warning(QString const & file, unsigned int line, QString const & function, QString const & message);
    void error(QString const & file, unsigned int line, QString const & function, QString const & message);
    void fatal(QString const & file, unsigned int line, QString const & function, QString const & message);

private:
    bool isLevelEnabled(LoggerConfiguration::LogLevel level) const;
    void write(LoggerConfiguration::LogLevel level, QString const & file, unsigned int line, QString const & function, QString const & message);

    QSharedPointer<IAppender> m_pAppender;
    QString m_Name;
};

}

#endif // RPILOGGER_H
