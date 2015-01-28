#include "exception.h"

using namespace rpi;


Exception::Exception(QString what)
    : m_What(what), m_Where("")
{
}

Exception::Exception(QString what, QString file, int line)
    : m_What(what), m_Where(file + ":" + QString::number(line))
{
}

Exception::Exception(QString what, QString file, int line, QString func)
    : m_What(what), m_Where(file + ":" + QString::number(line) + ": " + func)
{
}

QString Exception::what() const
{
    return m_What;
}

QString Exception::where() const
{
    return m_Where;
}

QString Exception::details() const
{
    return m_Where + ": " + m_What;
}
