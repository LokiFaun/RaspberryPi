#ifndef EXCEPTION_H
#define EXCEPTION_H

#pragma once

#include <QString>
#include "rpibase_global.h"

namespace rpi
{

class RPIBASESHARED_EXPORT Exception
{
public:
    explicit Exception(QString what);
    explicit Exception(QString what, QString file, int line);
    explicit Exception(QString what, QString file, int line, QString func);

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
