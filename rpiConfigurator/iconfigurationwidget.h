#ifndef CONFIGURATIONWIDGET_H__
#define CONFIGURATIONWIDGET_H__

#pragma once

#include <QMainWindow>

class IConfigurationWidget : public QMainWindow
{
    Q_OBJECT
public:
    virtual void saveConfiguration() = 0;
};

#endif // CONFIGURATIONWIDGET_H__
