#include "monitorconfig.h"
#include "../../qtjsonsettings/qtjsonsettings.h"
#include "logmanager.h"
#include "exception.h"

#include <QDebug>

using namespace rpi;

rpi::MonitorConfig &rpi::MonitorConfig::getInstance()
{
    static MonitorConfig m_Instance;
    return m_Instance;
}

bool rpi::MonitorConfig::load(const QString &fileName)
{
    QtJsonSettings settings(fileName);
    RPI_INFO("org.rpi.monitorconfig", "opening configuration from: " + fileName);

    const int count = settings.beginReadArray("ServiceMonitor/Services");
    for (int i = 0; i < count; ++i)
    {
        settings.setArrayIndex(i);
        ServiceConfig config;
        config.Id = i + 1;
        config.Name = settings.value("Name").toString();
        config.Timeout = settings.value("Timeout").toInt();
        m_ServiceConfigurations.push_back(config);
    }

    return false;
}

int rpi::MonitorConfig::getNumberOfServices() const
{
    return m_ServiceConfigurations.size();
}

int rpi::MonitorConfig::getServiceId(int index) const
{
    Q_ASSERT_X(index < getNumberOfServices(), Q_FUNC_INFO, "Index out of range");
    if (index < getNumberOfServices())
    {
        return m_ServiceConfigurations.at(index).Id;
    }
    THROW_EXCEPTION_DETAILED("index out of range");
}

QString rpi::MonitorConfig::getServiceName(int index) const
{
    Q_ASSERT_X(index < getNumberOfServices(), Q_FUNC_INFO, "Index out of range");
    if (index < getNumberOfServices())
    {
        return m_ServiceConfigurations.at(index).Name;
    }
    THROW_EXCEPTION_DETAILED("index out of range");
}

unsigned int rpi::MonitorConfig::getServiceTimeout(int index) const
{
    Q_ASSERT_X(index < getNumberOfServices(), Q_FUNC_INFO, "Index out of range");
    if (index < getNumberOfServices())
    {
        return m_ServiceConfigurations.at(index).Timeout;
    }
    THROW_EXCEPTION_DETAILED("index out of range");
}
