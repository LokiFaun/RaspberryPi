#include "servicemonitor.h"
#include "name_defs.h"
#include "command_defs.h"
#include "servicemonitorconfiguration.h"
#include "logmanager.h"
#include "service.h"
#include "exception.h"
#include "container.h"

#include <QFile>

using namespace rpi;

ServiceMonitor::ServiceMonitor(int argc, char ** argv) : QtService<QCoreApplication>(argc, argv, "rpiServiceMonitor")
{
    m_pContainer = QSharedPointer<Container>(new Container());
    load(argc, argv);
}

void ServiceMonitor::start()
{
    RPI_ERROR("rpiServiceMonitor", "starting service rpiServiceMonitor");

    ServiceMonitorConfiguration * pConfig = m_pContainer->getObject<ServiceMonitorConfiguration>();
    if (pConfig != NULL)
    {
        const int count = pConfig->count();
        for (int i = 0; i < count; ++i)
        {
            try
            {
                const int id = pConfig->id(i);
                const QString name = pConfig->name(i);
                const int timeout = pConfig->timeout(i);
                const QString configFile = pConfig->config(i);

                m_ServiceMap[id] = QSharedPointer<Service>(new Service(name, id, timeout, configFile));
            }
            catch (Exception const & ex)
            {
                RPI_ERROR("rpiServiceMonitor", ex.details());
            }
        }
    }

    startServices();
}

void ServiceMonitor::stop()
{
    stopServices();
}

void ServiceMonitor::processCommand(int code)
{
    int cmd = code & CMD_MASK;
    switch (cmd)
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
        if ((cmd & CMD_KEEP_ALIVE) == CMD_KEEP_ALIVE)
        {
            keepAlive(cmd & ~CMD_KEEP_ALIVE);
        }
        break;
    }
}

void ServiceMonitor::load(int argc, char ** argv)
{
    QStringList args;
    for (int i = 1; i < argc; ++i)
    {
        args.push_back(argv[i]);
    }

    RPI_DEBUG("rpiServiceMonitor", QString("loading service with arguments: ") + args.join(" "));

    QString fileName;
    // parse command line arguments
    for (QStringList::ConstIterator iter = args.constBegin(); iter != args.constEnd(); ++iter)
    {
        if (iter->compare("-config", Qt::CaseInsensitive) == 0)
        {
            ++iter;
            fileName = *iter;
        }
    }

    // check if passed file exists, set default file if not
    if (fileName.isEmpty() || !QFile::exists(fileName))
    {
        fileName = DefaultMonitorConfigFile;
    }

    // load configuration if the file exists
    if (QFile::exists(fileName))
    {
        ServiceMonitorConfiguration * pConfig = new ServiceMonitorConfiguration(fileName);
        m_pContainer->registerObject(pConfig);
    }
}

void ServiceMonitor::reboot()
{
    int result = system("shutdown now -r");
    RPI_INFO("rpiServiceMonitor", QString("system shutdown exited with code: %1").arg(result));
}

void ServiceMonitor::restart()
{
    RPI_INFO("rpiServiceMonitor", "restarting all services");
    stopServices();
    startServices();
}

void ServiceMonitor::keepAlive(int id)
{
    if (m_ServiceMap.contains(id))
    {
        RPI_INFO("rpiServiceMonitor", QString("keeping service #%1 alive").arg(QString::number(id)));
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
        RPI_INFO("rpiServiceMonitor", QString("starting service: %1").arg((*iter)->name()));
        (*iter)->start();
    }
}
