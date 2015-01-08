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
    void saveServices();
    void addNewService();
    void changeServiceId(int nr, int id);
    void changeServiceName(int nr, QString const & name);
    void changeServiceTimeout(int nr, unsigned int timeout);
    void changeServiceConfig(int nr, QString const & config);
    void removeService(QWidget * pWidget, int nr);

private:
    void clearConfigurations();

    ServiceMonitorConfiguration * m_pConfiguration;
    QVBoxLayout * m_pLayout;
    
};

