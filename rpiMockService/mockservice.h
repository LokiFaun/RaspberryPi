#ifndef MOCKSERVICE_H
#define MOCKSERVICE_H

#pragma once
#include <QtService.h>


class QCoreApplication;

namespace rpi
{
    class MockService : public QtService< QCoreApplication >
    {

    };
}

#endif // MOCKSERVICE_H

