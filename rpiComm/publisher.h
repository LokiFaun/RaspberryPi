#ifndef TEMPERATUREPUBLISHER_H
#define TEMPERATUREPUBLISHER_H

#pragma once

#include "rpicomm_global.h"

#include <mosquittopp.h>
#include <QString>

namespace rpi
{
    class RPICOMMSHARED_EXPORT Publisher : public mosquittopp::mosquittopp
    {
    public:
        explicit Publisher(QString const & id, QString const & topic, QString const & host, int port = 1883);
        virtual ~Publisher();

        bool SendMesage(QString const & message);

    private:
        virtual void on_connect(int rc);
        virtual void on_disconnect();
        virtual void on_error();

        QString m_Id;
        QString m_Topic;
        QString m_Host;
        int m_Port;
    };
}

#endif // TEMPERATUREPUBLISHER_H

