#ifndef CONTROLLERCONFIGURATION_H
#define CONTROLLERCONFIGURATION_H

#pragma once

#include "../rpiConfig/configuration.h"

namespace rpi
{
    class  ControllerConfiguration : public Configuration
    {
    public:

        explicit ControllerConfiguration(QString const& fileName, QObject* pParent);
        virtual ~ControllerConfiguration() { }
        
        ConfigurationType configurationType();


        bool isAutodimmingEnabled() const;
        unsigned int autodimmingMinValue() const;
        unsigned int autodimmingMaxValue() const;
        unsigned int autodimmingMinBrightness() const;
        unsigned int autodimmingMaxBrightness() const;
        unsigned int autodimmingUpdateIntervall() const;

        void setIsAutodimmingEnabled(bool isEnabled);
        void setAutodimmingMinValue(unsigned int minValue);
        void setAutodimmingMaxValue(unsigned int maxValue);
        void setAutodimmingMinBrightness(unsigned int min);
        void setAutodimmingMaxBrightness(unsigned int max);
        void setAutodimmingUpdateIntervall(unsigned int intervall);


        bool isTemperatureMonitorEnabled() const;
        unsigned int temperatureMonitorUpdateIntervall() const;

        void setIsTemperatureMonitorEnabled(bool isEnabled);
        void setTemperatureMonitorUpdateIntervall(unsigned int intervall);


        bool isServiceMonitorEnabled() const;
        QString serviceMonitor() const;
        unsigned int serviceMonitorUpdateInervall() const;

        void setIsServiceMonitorEnabled(bool isEnabled);
        void setServiceMonitor(QString const & monitor);
        void setServiceMonitorUpdateIntervall(unsigned int intervall);

        
    private:

        static const QString AutodimmingConfigurationPath;
        static const QString AutodimmingEnabledConfigurationPath;
        static const QString AutodimmingMinValueConfigurationPath;
        static const QString AutodimmingMaxValueConfigurationPath;
        static const QString AutodimmingMinBrightnessConfigurationPath;
        static const QString AutodimmingMaxBrightnessConfigurationPath;
        static const QString AutodimmingUpdateIntervallConfigurationPath;

        static const QString TemperatureMonitorConfigurationPath;
        static const QString TemperatureMonitorEnabledConfigurationPath;
        static const QString TemperatureMonitorUpdateIntervallConfigurationPath;

        static const QString ServiceMonitorConfigurationPath;
        static const QString ServiceMinitorEnabledConfigurationPath;
        static const QString ServiceMonitorMonitorConfigurationPath;
        static const QString ServiceMonitorUpdateIntervallConfigurationPath;

    };
}

#endif // CONTROLLERCONFIGURATION_H

