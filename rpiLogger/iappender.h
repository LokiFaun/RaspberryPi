#ifndef ABSTRACTAPPENDER_H
#define ABSTRACTAPPENDER_H

#pragma once

#include <QObject>

namespace rpi
{

class IAppender
{
public:
    virtual void write(QString const & message) = 0;
    virtual ~IAppender() { }
};

}

Q_DECLARE_INTERFACE(rpi::IAppender, "rpiIAppender")

#endif // ABSTRACTAPPENDER_H
