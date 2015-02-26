#include "exception.h"

using namespace rpi;


Exception::Exception(QObject * pParent/* = NULL*/)
    :QObject(pParent), m_What(""), m_Where("")
{
}

Exception::Exception(QString what, QObject * pParent/* = NULL*/)
    : QObject(pParent), m_What(what), m_Where("")
{
}

Exception::Exception(QString what, QString file, int line, QObject * pParent/* = NULL*/)
    : QObject(pParent), m_What(what), m_Where(file + ":" + QString::number(line))
{
}

Exception::Exception(QString what, QString file, int line, QString func, QObject * pParent/* = NULL*/)
    : QObject(pParent), m_What(what), m_Where(file + ":" + QString::number(line) + ": " + func)
{
}

Exception::Exception(Exception const & ex)
    : QObject(ex.d_ptr->parent)
{
    m_What = ex.m_What;
    m_Where = ex.m_Where;
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
