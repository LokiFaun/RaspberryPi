#include "servicemonitorconfiguration.h"
#include "..\rpiBase\exception.h"
#include "../../qtjsonsettings/qtjsonsettings.h"

using namespace rpi;


const QString ServiceMonitorConfiguration::ServiceConfigurationPath = "ServiceMonitor/Services";
const QString ServiceMonitorConfiguration::ServiceIdConfigurationPath = "Id";
const QString ServiceMonitorConfiguration::ServiceNameConfigurationPath = "Name";
const QString ServiceMonitorConfiguration::ServiceTimeoutConfigurationPath = "Timeout";


ServiceMonitorConfiguration::ServiceMonitorConfiguration(QString const & fileName) : Configuration(fileName) { }


ServiceMonitorConfiguration::~ServiceMonitorConfiguration() { }

void ServiceMonitorConfiguration::addService(int id, QString const & name, unsigned int timeout)
{
    m_Services.push_back(ServiceConfiguration(id, name, timeout));
}

void ServiceMonitorConfiguration::removeService(int index)
{
    m_Services.remove(index);
}

void ServiceMonitorConfiguration::setId(int index, int value)
{
    const int size = m_Services.size();
    Q_ASSERT_X(index >= 0 && index < size, Q_FUNC_INFO, "index out of range");
    if (index >= 0 && index < size)
    {
        m_Services[index].Id = value;
    }
    THROW_EXCEPTION_DETAILED("Index out of range");
}

void ServiceMonitorConfiguration::setName(int index, QString const & value)
{
    const int size = m_Services.size();
    Q_ASSERT_X(index >= 0 && index < size, Q_FUNC_INFO, "index out of range");
    if (index >= 0 && index < size)
    {
        m_Services[index].Name = value;
    }
    THROW_EXCEPTION_DETAILED("Index out of range");
}

void ServiceMonitorConfiguration::setTimeout(int index, unsigned int value)
{
    const int size = m_Services.size();
    Q_ASSERT_X(index >= 0 && index < size, Q_FUNC_INFO, "index out of range");
    if (index >= 0 && index < size)
    {
        m_Services[index].Timeout = value;
    }
    THROW_EXCEPTION_DETAILED("Index out of range");
}

int ServiceMonitorConfiguration::getId(int index) const
{
    const int size = m_Services.size();
    Q_ASSERT_X(index >= 0 && index < size, Q_FUNC_INFO, "index out of range");
    if (index >= 0 && index < size)
    {
        return m_Services[index].Id;
    }
    THROW_EXCEPTION_DETAILED("Index out of range");
}

const QString & ServiceMonitorConfiguration::getName(int index) const
{
    const int size = m_Services.size();
    Q_ASSERT_X(index >= 0 && index < size, Q_FUNC_INFO, "index out of range");
    if (index >= 0 && index < size)
    {
        return m_Services[index].Name;
    }
    THROW_EXCEPTION_DETAILED("Index out of range");
}

unsigned int ServiceMonitorConfiguration::getTimeout(int index) const
{
    const int size = m_Services.size();
    Q_ASSERT_X(index >= 0 && index < size, Q_FUNC_INFO, "index out of range");
    if (index >= 0 && index < size)
    {
        return m_Services[index].Timeout;
    }
    THROW_EXCEPTION_DETAILED("Index out of range");
}

int ServiceMonitorConfiguration::getCount() const
{
    return m_Services.size();
}

const ServiceMonitorConfiguration::Services & ServiceMonitorConfiguration::getServiceConfigurations() const
{
    return m_Services;
}

void ServiceMonitorConfiguration::save()
{
    QSharedPointer<QtJsonSettings> settings(new QtJsonSettings(m_ConfigurationFile));
    settings->beginWriteArray(ServiceConfigurationPath);

    int i = 0;
    for (Services::const_iterator iter = m_Services.begin(); iter != m_Services.end(); ++iter, ++i)
    {
        settings->setArrayIndex(i);
        settings->setValue(ServiceIdConfigurationPath, iter->Id);
        settings->setValue(ServiceNameConfigurationPath, iter->Name);
        settings->setValue(ServiceTimeoutConfigurationPath, iter->Timeout);
    }
}

ServiceMonitorConfiguration::ConfigurationType ServiceMonitorConfiguration::getConfigurationType()
{
    return Configuration::ServiceMonitor;
}

ServiceMonitorConfiguration::ServiceConfiguration::ServiceConfiguration(int id, QString const & name, unsigned int timeout) :Id(id), Name(name), Timeout(timeout) { }
