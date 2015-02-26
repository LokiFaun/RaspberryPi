#include "publisher.h"

#include <cerrno>

#include <QSharedPointer>

#include <mosquittopp.h>

using namespace rpi;

namespace rpi
{
    class MosquittoPublisher : public mosquittopp::mosquittopp
    {
    public:
        explicit MosquittoPublisher(Publisher * pPublisher, QString const & id, QString const & topic, QString const & host, int port = 1883);
        virtual ~MosquittoPublisher();

        bool send_mesage(QString const & message);

    private:
        virtual void on_connect(int rc);
        virtual void on_disconnect();
        virtual void on_error();

        Publisher * m_pPublisher;
        QString m_Id;
        QString m_Topic;
        QString m_Host;
        int m_Port;
    };

}

MosquittoPublisher::MosquittoPublisher(Publisher * pPublisher, QString const & id, QString const & topic, QString const & host, int port)
    :mosquittopp(id.toStdString().c_str()), m_Id(id), m_Topic(topic), m_Host(host)
{
    m_pPublisher = pPublisher;
    lib_init();
    connect(host.toStdString().c_str(), port);
}

MosquittoPublisher::~MosquittoPublisher()
{
    lib_cleanup();
}

bool MosquittoPublisher::send_mesage(QString const & message)
{
    return publish(NULL, m_Topic.toStdString().c_str(), message.size(), reinterpret_cast<const uint8_t *>(message.toStdString().c_str()), 1, false) == MOSQ_ERR_SUCCESS;
}

void MosquittoPublisher::on_connect(int rc)
{
    if (m_pPublisher != NULL)
    {
        emit m_pPublisher->OnConnect(rc);
    }
}

void MosquittoPublisher::on_disconnect()
{
    if (m_pPublisher != NULL)
    {
        emit m_pPublisher->OnDisconnect();
    }
}

void MosquittoPublisher::on_error()
{
    if (m_pPublisher != NULL)
    {
        emit m_pPublisher->OnError(strerror(errno));
    }
}

Publisher::Publisher(QString const& id, QString const& topic, QString const& host, int port)
{
    m_pPublisher = QSharedPointer<MosquittoPublisher>(new MosquittoPublisher(this, id, topic, host, port));
}

Publisher::~Publisher() { }

bool Publisher::SendMesage(QString const& message)
{
    if (m_pPublisher != NULL)
    {
        return m_pPublisher->send_mesage(message);
    }
    return false;
}
