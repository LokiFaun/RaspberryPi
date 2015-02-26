#ifndef SERVICEMONITORCONFIGURATION_H_
#define SERVICEMONITORCONFIGURATION_H_

#pragma once

#include "configuration.h"

class RPICONFIGSHARED_EXPORT ServiceMonitorConfiguration : public rpi::Configuration
{
    Q_OBJECT
public:

    explicit ServiceMonitorConfiguration(QString const & fileName, QObject * pParent = NULL);
    virtual ~ServiceMonitorConfiguration() { }

    virtual ConfigurationType configurationType();

    void setId(int index, int value);
    void setName(int index, QString const & value);
    void setTimeout(int index, unsigned int value);
    void setConfig(int index, QString const & value);

    int id(int index) const;
    QString name(int index) const;
    unsigned int timeout(int index) const;
    QString config(int index) const;

    int count() const;
    void remove(int index);

private:

    struct Service
    {
        int Id;
        QString Name;
        QString Config;
        unsigned int Timeout;
    };

    static const QString ServiceConfigurationPath;
    static const QString ServiceIdConfigurationPath;
    static const QString ServiceNameConfigurationPath;
    static const QString ServiceTimeoutConfigurationPath;
    static const QString ServiceConfigConfigurationPath;
};

#endif // SERVICEMONITORCONFIGURATION_H_
