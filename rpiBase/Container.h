#ifndef CONTAINER_H
#define CONTAINER_H

#pragma once

#include "rpibase_global.h"

#include <QObject>
#include <QMap>

namespace rpi
{
    class RPIBASESHARED_EXPORT Container : public QObject
    {
        Q_OBJECT
    public:
        explicit Container(QObject * pParent = NULL);

        void registerObject(QString const & key, QObject * pObject);
        void registerObject(QObject * pObject);

        template<typename T>
        T * getObject(QString const & key)
        {
            QObject * pObject = getObject(key);
            if (pObject != NULL)
            {
                return dynamic_cast<T *>(pObject);
            }
            return NULL;
        }

        template<typename T>
        T * getObject()
        {
            QMap<QString, QObject *>::const_iterator iter = m_Objects.begin();
            for (; iter != m_Objects.end(); ++iter)
            {
                T * pObject = dynamic_cast<T *>((*iter));
                if (pObject != NULL)
                {
                    return pObject;
                }
            }
            return NULL;
        }

    private:
        QObject * getObject(QString const & key);

        Container(const Container &); // hide copy constructor
        Container& operator=(const Container &); // hide assign op
    
        QMap<QString, QObject *> m_Objects;
    };
}

#endif // CONTAINER_H
