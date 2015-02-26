#include "controllerconfiguration.h"
#include "../../qtjsonsettings/qtjsonsettings.h"
#include "name_defs.h"

using namespace rpi;

const QString ControllerConfiguration::AutodimmingConfigurationPath = "Controller/Autodimming";
const QString ControllerConfiguration::AutodimmingEnabledConfigurationPath = "Enabled";
const QString ControllerConfiguration::AutodimmingMinValueConfigurationPath = "MinValue";
const QString ControllerConfiguration::AutodimmingMaxValueConfigurationPath = "MaxValue";
const QString ControllerConfiguration::AutodimmingMinBrightnessConfigurationPath = "MinBrightness";
const QString ControllerConfiguration::AutodimmingMaxBrightnessConfigurationPath = "MaxBrightness";
const QString ControllerConfiguration::AutodimmingUpdateIntervallConfigurationPath = "Intervall";

const QString ControllerConfiguration::TemperatureMonitorConfigurationPath = "Controller/TemperatureMonitor";
const QString ControllerConfiguration::TemperatureMonitorEnabledConfigurationPath = "Enabled";
const QString ControllerConfiguration::TemperatureMonitorUpdateIntervallConfigurationPath = "Intervall";

const QString ControllerConfiguration::ServiceMonitorConfigurationPath = "Controller/KeepAlive";
const QString ControllerConfiguration::ServiceMinitorEnabledConfigurationPath = "Enabled";
const QString ControllerConfiguration::ServiceMonitorMonitorConfigurationPath = "Monitor";
const QString ControllerConfiguration::ServiceMonitorUpdateIntervallConfigurationPath = "Intervall";


ControllerConfiguration::ControllerConfiguration(QString const & fileName, QObject * pParent /* = NULL*/)
    :Configuration(fileName, pParent)
{
}

Configuration::ConfigurationType ControllerConfiguration::configurationType()
{
    return Configuration::Controller;
}

bool ControllerConfiguration::isAutodimmingEnabled() const
{
    m_pSettings->beginGroup(AutodimmingConfigurationPath);
    bool const value = m_pSettings->value(AutodimmingEnabledConfigurationPath, DefaultAutodimmingEnabled).toBool();
    m_pSettings->endGroup();
    return value;
}

unsigned ControllerConfiguration::autodimmingMinValue() const
{
    m_pSettings->beginGroup(AutodimmingConfigurationPath);
    unsigned int const value = m_pSettings->value(AutodimmingMinValueConfigurationPath, DefaultAutodimmingMinValue).toUInt();
    m_pSettings->endGroup();
    return value;
}

unsigned ControllerConfiguration::autodimmingMaxValue() const
{
    m_pSettings->beginGroup(AutodimmingConfigurationPath);
    unsigned int const value = m_pSettings->value(AutodimmingMaxValueConfigurationPath, DefaultAutodimmingMaxValue).toUInt();
    m_pSettings->endGroup();
    return value;
}

unsigned ControllerConfiguration::autodimmingMinBrightness() const
{
    m_pSettings->beginGroup(AutodimmingConfigurationPath);
    unsigned int const value = m_pSettings->value(AutodimmingMinBrightnessConfigurationPath, DefaultAutodimmingMinBrightness).toUInt();
    m_pSettings->endGroup();
    return value;
}

unsigned ControllerConfiguration::autodimmingMaxBrightness() const
{
    m_pSettings->beginGroup(AutodimmingConfigurationPath);
    unsigned int const value = m_pSettings->value(AutodimmingMaxBrightnessConfigurationPath, DefaultAutodimmingMaxBrightness).toUInt();
    m_pSettings->endGroup();
    return value;
}

unsigned ControllerConfiguration::autodimmingUpdateIntervall() const
{
    m_pSettings->beginGroup(AutodimmingConfigurationPath);
    unsigned int const value = m_pSettings->value(AutodimmingUpdateIntervallConfigurationPath, DefaultAutodimmingUpdateIntervall).toUInt();
    m_pSettings->endGroup();
    return value;
}

void ControllerConfiguration::setIsAutodimmingEnabled(bool isEnabled)
{
    m_pSettings->beginGroup(AutodimmingConfigurationPath);
    m_pSettings->setValue(AutodimmingEnabledConfigurationPath, isEnabled);
    m_pSettings->endGroup();
}

void ControllerConfiguration::setAutodimmingMinValue(unsigned minValue)
{
    m_pSettings->beginGroup(AutodimmingConfigurationPath);
    m_pSettings->setValue(AutodimmingMinValueConfigurationPath, minValue);
    m_pSettings->endGroup();
}

void ControllerConfiguration::setAutodimmingMaxValue(unsigned maxValue)
{
    m_pSettings->beginGroup(AutodimmingConfigurationPath);
    m_pSettings->setValue(AutodimmingMaxValueConfigurationPath, maxValue);
    m_pSettings->endGroup();
}

void ControllerConfiguration::setAutodimmingMinBrightness(unsigned min)
{
    m_pSettings->beginGroup(AutodimmingConfigurationPath);
    m_pSettings->setValue(AutodimmingMinBrightnessConfigurationPath, min);
    m_pSettings->endGroup();
}

void ControllerConfiguration::setAutodimmingMaxBrightness(unsigned max)
{
    m_pSettings->beginGroup(AutodimmingConfigurationPath);
    m_pSettings->setValue(AutodimmingMaxValueConfigurationPath, max);
    m_pSettings->endGroup();
}

void ControllerConfiguration::setAutodimmingUpdateIntervall(unsigned intervall)
{
    m_pSettings->beginGroup(AutodimmingConfigurationPath);
    m_pSettings->setValue(AutodimmingUpdateIntervallConfigurationPath, intervall);
    m_pSettings->endGroup();
}

bool ControllerConfiguration::isTemperatureMonitorEnabled() const
{
    m_pSettings->beginGroup(TemperatureMonitorConfigurationPath);
    bool const value = m_pSettings->value(TemperatureMonitorEnabledConfigurationPath, DefaultTemperatureMonitorEnabled).toBool();
    m_pSettings->endGroup();
    return value;
}

unsigned ControllerConfiguration::temperatureMonitorUpdateIntervall() const
{
    m_pSettings->beginGroup(TemperatureMonitorConfigurationPath);
    unsigned int const value = m_pSettings->value(TemperatureMonitorUpdateIntervallConfigurationPath, DefaultTemperatureMonitorUpdateIntervall).toUInt();
    m_pSettings->endGroup();
    return value;
}

void ControllerConfiguration::setIsTemperatureMonitorEnabled(bool isEnabled)
{
    m_pSettings->beginGroup(TemperatureMonitorConfigurationPath);
    m_pSettings->setValue(TemperatureMonitorEnabledConfigurationPath, isEnabled);
    m_pSettings->endGroup();
}

void ControllerConfiguration::setTemperatureMonitorUpdateIntervall(unsigned intervall)
{
    m_pSettings->beginGroup(TemperatureMonitorConfigurationPath);
    m_pSettings->setValue(TemperatureMonitorUpdateIntervallConfigurationPath, intervall);
    m_pSettings->endGroup();
}

bool ControllerConfiguration::isServiceMonitorEnabled() const
{
    m_pSettings->beginGroup(ServiceMonitorConfigurationPath);
    bool const value = m_pSettings->value(ServiceMinitorEnabledConfigurationPath, DefaultServiceMonitorEnabled).toBool();
    m_pSettings->endGroup();
    return value;
}

QString ControllerConfiguration::serviceMonitor() const
{
    m_pSettings->beginGroup(ServiceMonitorConfigurationPath);
    QString const value = m_pSettings->value(ServiceMonitorMonitorConfigurationPath, DefaultServiceMonitor).toString();
    m_pSettings->endGroup();
    return value;
}

unsigned ControllerConfiguration::serviceMonitorUpdateInervall() const
{
    m_pSettings->beginGroup(ServiceMonitorConfigurationPath);
    unsigned int const value = m_pSettings->value(ServiceMonitorUpdateIntervallConfigurationPath, DefaultServiceMonitorUpdateIntervall).toUInt();
    m_pSettings->endGroup();
    return value;
}

void ControllerConfiguration::setIsServiceMonitorEnabled(bool isEnabled)
{
    m_pSettings->beginGroup(ServiceMonitorConfigurationPath);
    m_pSettings->setValue(ServiceMinitorEnabledConfigurationPath, isEnabled);
    m_pSettings->endGroup();
}

void ControllerConfiguration::setServiceMonitor(QString const & monitor)
{
    m_pSettings->beginGroup(ServiceMonitorConfigurationPath);
    m_pSettings->setValue(ServiceMonitorMonitorConfigurationPath, monitor);
    m_pSettings->endGroup();
}

void ControllerConfiguration::setServiceMonitorUpdateIntervall(unsigned intervall)
{
    m_pSettings->beginGroup(ServiceMonitorConfigurationPath);
    m_pSettings->setValue(ServiceMonitorUpdateIntervallConfigurationPath, intervall);
    m_pSettings->endGroup();
}
