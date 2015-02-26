#ifndef CONFIGURATIONWIDGET_H__
#define CONFIGURATIONWIDGET_H__

#pragma once

#include <QMainWindow>

class IConfigurationWidget : public QMainWindow
{
    Q_OBJECT
public:
    virtual void saveConfiguration() = 0;
    virtual void loadConfiguration() = 0;
    void setServiceConfigPath(QString const & path);

public slots:
    void install();
    void start();
    void stop();
    void setServicePath(QString const &);

signals:
    void configurationChanged();
    void configurationSaved();

private:
    QString m_ServiceConfigurationPath;
    QString m_ServicePath;
};

#endif // CONFIGURATIONWIDGET_H__

