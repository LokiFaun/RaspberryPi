#ifndef MONITORCONFIG_H
#define MONITORCONFIG_H

#include <QObject>
#include <QVector>
#include <QString>

#include "loggerconfiguration.h"

namespace rpi
{

class MonitorConfig : public QObject
{
    Q_OBJECT
public:
    static MonitorConfig & getInstance();

    bool load(QString const & fileName);

    int getNumberOfServices() const;
    int getServiceId(int index) const;
    QString getServiceName(int index) const;
    unsigned int getServiceTimeout(int index) const;

private:
    MonitorConfig() { }
    virtual ~MonitorConfig() { }
    MonitorConfig(MonitorConfig const &);
    MonitorConfig & operator = (MonitorConfig const &);

    struct ServiceConfig
    {
        int Id;
        QString Name;
        unsigned int Timeout;
    };

    QVector<ServiceConfig> m_ServiceConfigurations;

};

}

#endif // MONITORCONFIG_H
