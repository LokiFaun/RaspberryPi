#ifndef RPILOGGER_H
#define RPILOGGER_H

#pragma once

#include "rpilogger_global.h"

#include <QObject>

namespace rpi
{

class RPILOGGERSHARED_EXPORT RpiLogger : public QObject
{
    Q_OBJECT

public:
    explicit RpiLogger();
    explicit RpiLogger(QString const & name, QObject * pParent = 0);
    virtual ~RpiLogger();

    void debug(QString const & file, unsigned int line, QString const & function, QString const & message);
    void trace(QString const & file, unsigned int line, QString const & function, QString const & message);
    void info(QString const & file, unsigned int line, QString const & function, QString const & message);
    void warning(QString const & file, unsigned int line, QString const & function, QString const & message);
    void error(QString const & file, unsigned int line, QString const & function, QString const & message);
    void fatal(QString const & file, unsigned int line, QString const & function, QString const & message);

private:

    QString m_Name;
};

}

#endif // RPILOGGER_H
