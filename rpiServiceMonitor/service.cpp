#include "service.h"
#include "logmanager.h"

#include <QMutexLocker>
#include <QtServiceController>

using namespace rpi;

Service::Service(const QString &name, unsigned int id, unsigned int timeout, QObject *pParent)
    : QThread(pParent), m_Name(name), m_Id(id), m_Timeout(timeout)
{
    m_IsRunning = false;
}

QString Service::name() const
{
    return m_Name;
}

unsigned int Service::id() const
{
    return m_Id;
}

unsigned int Service::timeout() const
{
    return m_Timeout;
}

bool Service::IsRunning()
{
    QMutexLocker lock(&m_CSShutdown);
    return m_IsRunning;
}

void Service::setArguments(const QStringList &args)
{
    m_Arguments = args;
}

void Service::keepAlive()
{
    m_WaitKeepAlive.wakeAll();
}

void Service::stop()
{
    QMutexLocker lock(&m_CSShutdown);
    m_IsRunning = false;
    QtServiceController controller(m_Name);
    if (controller.isRunning())
    {
        controller.stop();
    }
}

void Service::run()
{
    m_IsRunning = true;
    QtServiceController controller(m_Name);
    if (!controller.isInstalled())
    {
        RPI_ERROR("rpiServiceMonitor", QString("service %1 not installed").arg(m_Name));
        return;
    }
    controller.start(m_Arguments);

    if (!controller.isRunning())
    {
        RPI_ERROR("rpiServiceMonitor", QString("service %1 could not be started").arg(m_Name));
        return;
    }

    while (IsRunning())
    {
        if (!m_WaitKeepAlive.wait(&m_CSKeepAlive, m_Timeout))
        {
            emit Timeout(m_Id);
            m_IsRunning = false;
        }
        if (!controller.isRunning())
        {
            emit Timeout(m_Id);
            m_IsRunning = false;
        }
    }
}


