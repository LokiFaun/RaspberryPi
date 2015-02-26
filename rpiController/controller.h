#ifndef CONTOLLER_H_
#define CONTOLLER_H_

#pragma once

#include <QtService.h>
#include <QSharedPointer>

namespace rpi
{
    class Container;

    class Controller : public QtService<QCoreApplication>
    {
    public:
        explicit Controller(int argc, char ** argv);
        virtual ~Controller();

        // QtServiceBase interface
    protected:
        virtual void start();
        virtual void stop();
        virtual void processCommand(int code);

    private:

        void load(int argc, char ** argv);

        QSharedPointer<Container> m_pContainer;
    };
}

#endif // CONTOLLER_H_

