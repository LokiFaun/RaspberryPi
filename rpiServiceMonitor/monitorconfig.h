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
    static MonitorConfig & instance();

    bool load(QString const & fileName);

    int count() const;
    int id(int index) const;
    QString name(int index) const;
    unsigned int timeout(int index) const;
    QString config(int index) const;

    static const QString ServiceConfigurationPath;
    static const QString ServiceIdConfigurationPath;
    static const QString ServiceNameConfigurationPath;
    static const QString ServiceTimeoutConfigurationPath;
    static const QString ServiceConfigConfigurationPath;

private:
    MonitorConfig() { }
    virtual ~MonitorConfig() { }
    MonitorConfig(MonitorConfig const &);
    MonitorConfig & operator = (MonitorConfig const &);

    QSharedPointer<QtJsonSettings> m_pSettings;
};

}

#endif // MONITORCONFIG_H
