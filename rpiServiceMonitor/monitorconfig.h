#ifndef MONITORCONFIG_H
#define MONITORCONFIG_H

#include <QObject>
#include <QVector>
#include <QString>
#include <QSharedPointer>

#include "loggerconfiguration.h"
#include "../../qtjsonsettings/qtjsonsettings.h"

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

    static const QString ServiceConfigurationPath;
    static const QString ServiceNameConfigurationPath;
    static const QString ServiceTimeoutConfigurationPath;

private:
    MonitorConfig() { }
    virtual ~MonitorConfig() { }
    MonitorConfig(MonitorConfig const &);
    MonitorConfig & operator = (MonitorConfig const &);

    QSharedPointer<QtJsonSettings> m_pSettings;
};

}

#endif // MONITORCONFIG_H
