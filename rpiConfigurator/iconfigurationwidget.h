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

signals:
    void configurationChanged();
    void configurationSaved();
};

#endif // CONFIGURATIONWIDGET_H__
