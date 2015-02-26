#ifndef EXCEPTION_H
#define EXCEPTION_H

#pragma once

#include "rpibase_global.h"

#include <QObject>
#include <QString>

namespace rpi
{

class RPIBASESHARED_EXPORT Exception : public QObject
{
    Q_OBJECT
public:
    explicit Exception(QObject * pParent = NULL);
    explicit Exception(QString what, QObject * pParent = NULL);
    explicit Exception(QString what, QString file, int line, QObject * pParent = NULL);
    explicit Exception(QString what, QString file, int line, QString func, QObject * pParent = NULL);
    Exception(Exception const &ex);
    virtual ~Exception() { }

    QString what() const;
    QString where() const;
    QString details() const;

private:
    QString m_What;
    QString m_Where;
};

#define THROW_EXCEPTION(what) \
    throw Exception(what);

#define THROW_EXCEPTION_DETAILED(what) \
    throw Exception(what, __FILE__, __LINE__, Q_FUNC_INFO);

}

#endif // EXCEPTION_H
