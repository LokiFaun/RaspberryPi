#pragma once

#include "iconfigurationwidget.h"
#include "servicemonitorconfiguration.h"

#include <QVBoxLayout>

class ServiceMonitorConfigurationWidget : public IConfigurationWidget
{
    Q_OBJECT
public:
    ServiceMonitorConfigurationWidget(ServiceMonitorConfiguration * config);
    virtual ~ServiceMonitorConfigurationWidget();

    virtual void saveConfiguration();

public slots:
    void addNewService();

private:
    ServiceMonitorConfiguration * m_pConfiguration;
    QVBoxLayout * m_pLayout;
};

