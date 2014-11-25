#include "exception.h"

using namespace rpi;


rpi::Exception::Exception(QString what)
    : m_What(what), m_Where("")
{
}

rpi::Exception::Exception(QString what, QString file, int line)
    : m_What(what), m_Where(file + ":" + QString::number(line))
{
}

rpi::Exception::Exception(QString what, QString file, int line, QString func)
    : m_What(what), m_Where(file + ":" + QString::number(line) + ": " + func)
{
}

QString rpi::Exception::what() const
{
    return m_What;
}

QString rpi::Exception::where() const
{
    return m_Where;
}

QString rpi::Exception::details() const
{
    return m_Where + ": " + m_What;
}
