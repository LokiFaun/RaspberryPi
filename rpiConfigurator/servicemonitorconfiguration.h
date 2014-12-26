#ifndef SERVICEMONITORCONFIGURATION_H_
#define SERVICEMONITORCONFIGURATION_H_

#pragma once

#include "configuration.h"
#include <QVector>

class ServiceMonitorConfiguration : public Configuration
{
public:

    struct ServiceConfiguration
    {
        int Id;
        QString Name;
        unsigned int Timeout;

        ServiceConfiguration() { }
        ServiceConfiguration(int id, QString const & name, unsigned int timeout);
    };

    typedef QVector<ServiceConfiguration> Services;

    ServiceMonitorConfiguration(QString const & fileName, QObject * pParent = NULL);
    virtual ~ServiceMonitorConfiguration();

    void addService(int id, QString const & name, unsigned int timeout);
    void removeService(int index);

    void setId(int index, int value);
    void setName(int index, QString const & value);
    void setTimeout(int index, unsigned int value);

    int id(int index) const;
    const QString & name(int index) const;
    unsigned int timeout(int index) const;

    int count() const;
    const Services & serviceConfigurations() const;

    virtual void save();
    virtual ConfigurationType configurationType();

    static const QString ServiceConfigurationPath;
    static const QString ServiceIdConfigurationPath;
    static const QString ServiceNameConfigurationPath;
    static const QString ServiceTimeoutConfigurationPath;

private:
    Services m_Services;
};

#endif // SERVICEMONITORCONFIGURATION_H_
