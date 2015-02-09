#include "publisher.h"
#include <cerrno>

rpi::Publisher::Publisher(QString const & id, QString const & topic, QString const & host, int port)
    :mosquittopp(id.toStdString().c_str()), m_Id(id), m_Topic(topic), m_Host(host)
{
    lib_init();
    connect(host.toStdString().c_str(), port);
}

rpi::Publisher::~Publisher()
{
    lib_cleanup();
}

bool rpi::Publisher::SendMesage(QString const & message)
{
    return publish(NULL, m_Topic.toStdString().c_str(), message.size(), reinterpret_cast<const uint8_t *>(message.toStdString().c_str()), 1, false) == MOSQ_ERR_SUCCESS;
}

void rpi::Publisher::on_connect(int /*rc*/)
{
}

void rpi::Publisher::on_disconnect()
{
}

void rpi::Publisher::on_error()
{
}