#pragma once

#include "iconfigurationwidget.h"
#include "servicemonitorconfiguration.h"
#include "serviceconfigurationwidget.h"

#include <QVBoxLayout>
#include <QVector>

class ServiceMonitorConfigurationWidget : public IConfigurationWidget
{
    Q_OBJECT
public:
    ServiceMonitorConfigurationWidget(ServiceMonitorConfiguration * config);
    virtual ~ServiceMonitorConfigurationWidget();

    virtual void saveConfiguration();
    virtual void loadConfiguration();

public slots:
    void addNewService();
    void removeService(QWidget * pWidget);

private:
    void clearConfigurations();

    ServiceMonitorConfiguration * m_pConfiguration;
    QVector<ServiceConfigurationWidget *> m_ServiceConfigurations;
    QVBoxLayout * m_pLayout;
    
};

