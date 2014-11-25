#ifndef SERVICEMONITOR_H
#define SERVICEMONITOR_H

#include <QtService.h>
#include <QCoreApplication>
#include <QMap>
#include <QSharedPointer>

#include "service.h"

namespace rpi
{

class ServiceMonitor : public QtService<QCoreApplication>
{
public:
    explicit ServiceMonitor(int argc, char **argv);

    typedef QMap<unsigned int, QSharedPointer<Service> > ServiceMap;

    // QtServiceBase interface
protected:
    virtual void start();
    virtual void stop();
    virtual void processCommand(int code);

private:
    void load(int argc, char ** argv);
    void reboot();
    void restart();
    void keepAlive(int id);
    void stopServices();
    void startServices();

    ServiceMap m_ServiceMap;
};

}

#endif // SERVICEMONITOR_H
