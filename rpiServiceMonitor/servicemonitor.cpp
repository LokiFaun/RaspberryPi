#include "servicemonitor.h"
#include "name_defs.h"
#include "command_defs.h"
#include "monitorconfig.h"
#include "logmanager.h"
#include "service.h"
#include "exception.h"

#include <typeinfo>

#include "../../qtjsonsettings/qtjsonsettings.h"

using namespace rpi;

ServiceMonitor::ServiceMonitor(int argc, char **argv) : QtService<QCoreApplication>(argc, argv, "rpiServiceMonitor")
{
    load(argc, argv);
}

void ServiceMonitor::start()
{
    RPI_ERROR("org.rpi.servicemonitor", "starting service rpiServiceMonitor");
    startServices();
}

void ServiceMonitor::stop()
{
    stopServices();
}

void ServiceMonitor::processCommand(int code)
{
    switch (code)
    {
    case CMD_STOP:
        stopServices();
        break;
    case CMD_REBOOT:
        reboot();
        break;
    case CMD_RESTART:
        restart();
        break;
    default:
        if ((code & CMD_KEEP_ALIVE) == CMD_KEEP_ALIVE)
        {
            keepAlive(code & ~CMD_KEEP_ALIVE);
        }
        break;
    }
}

void ServiceMonitor::load(int argc, char **argv)
{
    QStringList args;
    for (int i = 1; i < argc; ++i)
    {
        args.push_back(argv[i]);
    }

    RPI_DEBUG("org.rpi.servicemonitor", QString("loading service with arguments: ") + args.join(" "));
    QString fileName = DefaultMonitorConfigFile;

    for (int i = 0; i < argc - 1; ++i)
    {
        QString id(argv[i]);
        QString arg(argv[i + 1]);

        if (id.compare("-config", Qt::CaseInsensitive) == 0)
        {
            fileName = arg;
        }
    }

    MonitorConfig & config = MonitorConfig::getInstance();
    config.load(fileName);
    const int count = config.getNumberOfServices();
    for (int i = 0; i < count; ++i)
    {
        try
        {
        const int id = config.getServiceId(i);
        const QString name = config.getServiceName(i);
        const int timeout = config.getServiceTimeout(i);

        m_ServiceMap[id] = QSharedPointer<Service>(new Service(name, id, timeout));
        }
        catch (Exception const & ex)
        {
            RPI_ERROR("org.rpi.servicemonitor", ex.details());
        }
    }
}

void ServiceMonitor::reboot()
{
    system("shutdown now -r");
}

void ServiceMonitor::restart()
{
    RPI_INFO("org.rpi.servicemonitor", "restarting all services");
    stopServices();
    startServices();
}

void ServiceMonitor::keepAlive(int id)
{
    if (m_ServiceMap.contains(id))
    {
        RPI_INFO("org.rpi.servicemonitor", QString("keeping service #%1 alive").arg(QString::number(id)));
        m_ServiceMap[id]->keepAlive();
    }
}

void ServiceMonitor::stopServices()
{
    for (ServiceMap::iterator iter = m_ServiceMap.begin(); iter != m_ServiceMap.end(); ++iter)
    {
        (*iter)->stop();
    }
}

void ServiceMonitor::startServices()
{
    for (ServiceMap::iterator iter = m_ServiceMap.begin(); iter != m_ServiceMap.end(); ++iter)
    {
        RPI_INFO("org.rpi.servicemonitor", QString("starting service: %1").arg((*iter)->getName()));
        (*iter)->start();
    }
}