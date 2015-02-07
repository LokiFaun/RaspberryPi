#ifndef CONFIGURATION_H_
#define CONFIGURATION_H_

#pragma once

#include "rpiconfig_global.h"
#include <QObject>

class QtJsonSettings;

namespace rpi
{
    class RPICONFIGSHARED_EXPORT Configuration : public QObject
    {
        Q_OBJECT
            Q_ENUMS(ConfigurationType);

    public:

        enum ConfigurationType
        {
            ServiceMonitor,
            Controller
        };

        explicit Configuration(QString const & fileName, QObject * pParent = NULL);
        virtual ~Configuration() { }

        virtual ConfigurationType configurationType() = 0;
        QString configurationFile() const;

        QString loggingFilename() const;
        QString loggingLevel() const;
        int loggingFileSize() const;
        int loggingFileCount() const;

        void setLoggingFilename(QString const & fileName);
        void setLoggingLevel(QString const & level);
        void setLoggingFileSize(int size);
        void setLoggingFileCount(int count);

        void sync();

    signals:

        void configurationChanged();

    protected:

        static const QString LoggingConfigurationPath;
        static const QString LoggingFileNameConfigurationPath;
        static const QString LoggingLevelConfigurationPath;
        static const QString LoggingFileSizeConfigurationPath;
        static const QString LoggingFileCountConfigurationPath;


        QtJsonSettings * m_pSettings;
        QString m_ConfigurationFile;
    };
}

#endif // CONFIGURATION_H_
