#include "servicemonitorconfiguration.h"
#include "../../qtjsonsettings/qtjsonsettings.h"
#include <QVector>

using namespace rpi;


const QString ServiceMonitorConfiguration::ServiceConfigurationPath = "ServiceMonitor/Services";
const QString ServiceMonitorConfiguration::ServiceIdConfigurationPath = "Id";
const QString ServiceMonitorConfiguration::ServiceNameConfigurationPath = "Name";
const QString ServiceMonitorConfiguration::ServiceTimeoutConfigurationPath = "Timeout";
const QString ServiceMonitorConfiguration::ServiceConfigConfigurationPath = "Config";


ServiceMonitorConfiguration::ServiceMonitorConfiguration(QString const & fileName, QObject * pParent /*= NULL*/) : Configuration(fileName, pParent)
{
}

ServiceMonitorConfiguration::ConfigurationType ServiceMonitorConfiguration::configurationType()
{
    return Configuration::ServiceMonitor;
}

void ServiceMonitorConfiguration::setId(int index, int value)
{
    m_pSettings->beginWriteArray(ServiceConfigurationPath);
    m_pSettings->setArrayIndex(index);
    m_pSettings->setValue(ServiceIdConfigurationPath, value);
    m_pSettings->endArray();
}

void ServiceMonitorConfiguration::setName(int index, QString const & value)
{
    m_pSettings->beginWriteArray(ServiceConfigurationPath);
    m_pSettings->setArrayIndex(index);
    m_pSettings->setValue(ServiceNameConfigurationPath, value);
    m_pSettings->endArray();
}

void ServiceMonitorConfiguration::setTimeout(int index, unsigned int value)
{
    m_pSettings->beginWriteArray(ServiceConfigurationPath);
    m_pSettings->setArrayIndex(index);
    m_pSettings->setValue(ServiceTimeoutConfigurationPath, value);
    m_pSettings->endArray();
}

void ServiceMonitorConfiguration::setConfig(int index, QString const & value)
{
    m_pSettings->beginWriteArray(ServiceConfigurationPath);
    m_pSettings->setArrayIndex(index);
    m_pSettings->setValue(ServiceConfigConfigurationPath, value);
    m_pSettings->endArray();
}

int ServiceMonitorConfiguration::id(int index) const
{
    m_pSettings->beginReadArray(ServiceConfigurationPath);
    m_pSettings->setArrayIndex(index);
    int const value = m_pSettings->value(ServiceConfigConfigurationPath, 0).toInt();
    m_pSettings->endArray();
    return value;
}

QString ServiceMonitorConfiguration::name(int index) const
{
    m_pSettings->beginReadArray(ServiceConfigurationPath);
    m_pSettings->setArrayIndex(index);
    QString const value = m_pSettings->value(ServiceNameConfigurationPath, 0).toString();
    m_pSettings->endArray();
    return value;
}

unsigned int ServiceMonitorConfiguration::timeout(int index) const
{
    m_pSettings->beginReadArray(ServiceConfigurationPath);
    m_pSettings->setArrayIndex(index);
    unsigned int const value = m_pSettings->value(ServiceTimeoutConfigurationPath, 0).toUInt();
    m_pSettings->endArray();
    return value;
}

QString ServiceMonitorConfiguration::config(int index) const
{
    m_pSettings->beginReadArray(ServiceConfigurationPath);
    m_pSettings->setArrayIndex(index);
    QString const value = m_pSettings->value(ServiceConfigConfigurationPath, 0).toString();
    m_pSettings->endArray();
    return value;
}

int ServiceMonitorConfiguration::count() const
{
    return m_pSettings->beginReadArray(ServiceConfigurationPath);
}

void ServiceMonitorConfiguration::remove(int index)
{
    QVector<Service> services;

    const int count = m_pSettings->beginReadArray(ServiceConfigurationPath);
    for (int i = 0; i < count; ++i)
    {
        if (i == index)
        {
            continue;
        }
        services.push_back({
                               m_pSettings->value(ServiceIdConfigurationPath).toInt(),
                               m_pSettings->value(ServiceNameConfigurationPath).toString(),
                               m_pSettings->value(ServiceConfigConfigurationPath).toString(),
                               m_pSettings->value(ServiceTimeoutConfigurationPath).toUInt()
                           });
    }
    m_pSettings->endArray();

    m_pSettings->beginGroup(ServiceConfigurationPath);
    m_pSettings->remove("");
    m_pSettings->endGroup();

    const int newCount = services.size();
    m_pSettings->beginWriteArray(ServiceConfigurationPath, newCount);
    for (int i = 0; i < newCount; ++i)
    {
        m_pSettings->setValue(ServiceIdConfigurationPath, services[i].Id);
        m_pSettings->setValue(ServiceNameConfigurationPath, services[i].Name);
        m_pSettings->setValue(ServiceConfigConfigurationPath, services[i].Config);
        m_pSettings->setValue(ServiceTimeoutConfigurationPath, services[i].Timeout);
    }
    m_pSettings->endArray();
}
