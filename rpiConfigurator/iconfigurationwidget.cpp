#include "iconfigurationwidget.h"
#include "logmanager.h"

#include <QtServiceController>
#include <QMessageBox>

using namespace rpi;

void IConfigurationWidget::setServiceConfigPath(QString const & path)
{
    RPI_DEBUG("org.rpi.configurator.iconfigurationwidget", "Setting service configuration path: " + path);
    m_ServiceConfigurationPath = path;
}

void IConfigurationWidget::setServicePath(QString const & path)
{
    RPI_DEBUG("org.rpi.configurator.iconfigurationwidget", "Setting service path: " + path);
    m_ServicePath = path;
}

void IConfigurationWidget::install()
{
    if (m_ServicePath.isEmpty())
    {
        QMessageBox::warning(this, "Error", "No service specified!");
        return;
    }

    QtServiceController service(m_ServicePath);
    if (!service.install(m_ServicePath))
    {
        QMessageBox::critical(this, "Error", QString("Could not install the service %1!").arg(m_ServicePath));
    }
}

void IConfigurationWidget::start()
{
    if (m_ServicePath.isEmpty())
    {
        QMessageBox::warning(this, "Error", "No service specified!");
        return;
    }

    QtServiceController service(m_ServicePath);
    if (!service.start(QStringList("-config " + m_ServiceConfigurationPath)))
    {
        QMessageBox::critical(this, "Error", QString("Could not start the service %1!").arg(m_ServicePath));
    }
}

void IConfigurationWidget::stop()
{
    if (m_ServicePath.isEmpty())
    {
        QMessageBox::warning(this, "Error", "No service specified!");
        return;
    }
    QtServiceController service(m_ServicePath);
     
    if (service.isRunning() && !service.stop())
    {
        QMessageBox::critical(this, "Error", QString("Could not stop the service %1!").arg(m_ServicePath));
    }
}
