#include "monitorconfig.h"
#include "logmanager.h"
#include "exception.h"

using namespace rpi;

const QString rpi::MonitorConfig::ServiceConfigurationPath = "ServiceMonitor/Services";
const QString rpi::MonitorConfig::ServiceIdConfigurationPath = "Id";
const QString rpi::MonitorConfig::ServiceNameConfigurationPath = "Name";
const QString rpi::MonitorConfig::ServiceTimeoutConfigurationPath = "Timeout";

rpi::MonitorConfig &rpi::MonitorConfig::instance()
{
    static MonitorConfig m_Instance;
    return m_Instance;
}

bool rpi::MonitorConfig::load(const QString &fileName)
{
    m_pSettings = QSharedPointer<QtJsonSettings>(new QtJsonSettings(fileName));
    RPI_INFO("org.rpi.monitorconfig", "opening configuration from: " + fileName);
    return m_pSettings->beginReadArray(ServiceConfigurationPath) > 0;
}

int rpi::MonitorConfig::count() const
{
    return m_pSettings->beginReadArray(ServiceConfigurationPath);
}

int rpi::MonitorConfig::id(int index) const
{
    const int count = m_pSettings->beginReadArray(ServiceConfigurationPath);
    Q_ASSERT_X(index > 0 && index < count, Q_FUNC_INFO, "Index out of range");
    if (index > 0 && index < count)
    {
        m_pSettings->setArrayIndex(index);
        return m_pSettings->value(ServiceIdConfigurationPath).toInt();
    }
    THROW_EXCEPTION_DETAILED("index out of range");
}

QString rpi::MonitorConfig::name(int index) const
{
    const int count = m_pSettings->beginReadArray(ServiceConfigurationPath);
    Q_ASSERT_X(index > 0 && index < count, Q_FUNC_INFO, "Index out of range");
    if (index > 0 && index < count)
    {
        m_pSettings->setArrayIndex(index);
        return m_pSettings->value(ServiceNameConfigurationPath).toString();
    }
    THROW_EXCEPTION_DETAILED("index out of range");
}

unsigned int rpi::MonitorConfig::timeout(int index) const
{
    const int count = m_pSettings->beginReadArray(ServiceConfigurationPath);
    Q_ASSERT_X(index > 0 && index < count, Q_FUNC_INFO, "Index out of range");
    if (index > 0 && index < count)
    {
        m_pSettings->setArrayIndex(index);
        return m_pSettings->value(ServiceTimeoutConfigurationPath).toUInt();
    }
    THROW_EXCEPTION_DETAILED("index out of range");
}
