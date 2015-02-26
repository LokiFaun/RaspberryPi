#ifndef TEMPERATUREPUBLISHER_H
#define TEMPERATUREPUBLISHER_H

#pragma once

#include "rpicomm_global.h"

#include <QObject>
#include <QSharedPointer>

namespace rpi
{
    class MosquittoPublisher;

    class RPICOMMSHARED_EXPORT Publisher : public QObject
    {
        Q_OBJECT
    public:
        friend class MosquittoPublisher;

        explicit Publisher(QString const & id, QString const & topic, QString const & host, int port = 1883);
        virtual ~Publisher();

        bool SendMesage(QString const & message);

    signals:
        void OnConnect(int rc);
        void OnDisconnect();
        void OnError(QString const & error);

    private:
        QSharedPointer<MosquittoPublisher> m_pPublisher;
        QString m_Id;
        QString m_Topic;
        QString m_Host;
        int m_Port;
    };
}

#endif // TEMPERATUREPUBLISHER_H

