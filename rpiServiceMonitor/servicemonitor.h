#ifndef SERVICEMONITOR_H
#define SERVICEMONITOR_H

#pragma once

#include <QtService.h>
#include <QMap>
#include <QSharedPointer>

namespace rpi
{
    class Container;
    class Service;

    class ServiceMonitor : public QtService<QCoreApplication>
    {
    public:
        explicit ServiceMonitor(int argc, char ** argv);

        virtual ~ServiceMonitor()
        {
        }

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
        QSharedPointer<Container> m_pContainer;
    };
}

#endif // SERVICEMONITOR_H

