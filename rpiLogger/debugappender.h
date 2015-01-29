#ifndef DEBUGAPPENDER_H
#define DEBUGAPPENDER_H

#pragma once

#include "iappender.h"

namespace rpi
{

class DebugAppender : public QObject, public IAppender
{
    Q_OBJECT
public:
    explicit DebugAppender(QObject *parent = 0);

    virtual void write(QString const & message);
};

}

#endif // DEBUGAPPENDER_H
