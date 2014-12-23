#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#pragma once

#include <QMainWindow>
#include <QSharedPointer>
#include <QVector>
#include <QTabWidget>
#include "configurationtabfactory.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected slots:
    void aboutQt();
    void newConfiguration();
    void saveConfiguration();
    void openConfiguration();
    void closeWindow();
    void closeTab(int id);

private:
    void connectMenubarSlots();
    void createTabWidget();

    QSharedPointer<Ui::MainWindow> m_Ui;
    QSharedPointer<ConfigurationTabFactory> m_TabFactory;
    QTabWidget * m_TabWidget;
};

#endif // MAINWINDOW_H
