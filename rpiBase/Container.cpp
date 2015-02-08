#include "Container.h"

using namespace rpi;

Container::Container(QObject* pParent /*= NULL*/) : QObject(pParent) { }

void Container::registerObject(QString const& key, QObject* pObject)
{
    if (m_Objects.contains(key))
    {
        m_Objects[key]->setParent(NULL);
        delete m_Objects[key];
    }
    pObject->setParent(this);
    m_Objects[key] = pObject;
}

void Container::registerObject(QObject* pObject)
{
    const QString key = pObject->metaObject()->className();
    if (m_Objects.contains(key))
    {
        m_Objects[key]->setParent(NULL);
        delete m_Objects[key];
    }
    pObject->setParent(this);
    m_Objects[key] = pObject;
}

QObject* Container::getObject(QString const& key)
{
    if (m_Objects.contains(key))
    {
        return m_Objects[key];
    }
    return NULL;
}