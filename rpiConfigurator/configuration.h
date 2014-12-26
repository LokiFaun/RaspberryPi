#ifndef CONFIGURATION_H_
#define CONFIGURATION_H_

#pragma once

#include <QObject>
#include <QMap>
#include <QSharedPointer>

class Configuration : public QObject
{
    Q_OBJECT
    Q_ENUMS(ConfigurationType);

public:

    typedef QMap<QString, QSharedPointer<Configuration> > ConfigurationMap;

    enum ConfigurationType
    {
        ServiceMonitor,
        Controller,
        Logger
    };

    Configuration(QString const & fileName, QObject * pParent = NULL);
    virtual ~Configuration();

    virtual void save() = 0;
    virtual ConfigurationType configurationType() = 0;

    QString configurationFile() const;
    void setConfigurationFile(QString const & value);

protected:
    QString m_ConfigurationFile;
};

#endif // CONFIGURATION_H_
