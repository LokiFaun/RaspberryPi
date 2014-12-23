#ifndef CONFIGURATION_H_
#define CONFIGURATION_H_

#pragma once

#include <QObject>
#include <QMap>
#include <QSharedPointer>

class Configuration : public QObject
{
    Q_ENUMS(ConfigurationType);

public:

    typedef QMap<QString, QSharedPointer<Configuration> > ConfigurationMap;

    enum ConfigurationType
    {
        ServiceMonitor,
        Controller,
        Logger
    };

    Configuration(QString const & fileName);
    virtual ~Configuration();

    virtual void save() = 0;
    virtual ConfigurationType getConfigurationType() = 0;

    QString getConfigurationFile() const;
    void setConfigurationFile(QString const & value);

protected:
    QString m_ConfigurationFile;
};

#endif // CONFIGURATION_H_
