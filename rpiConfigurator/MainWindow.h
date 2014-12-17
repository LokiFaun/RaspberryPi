#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSharedPointer>

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

private:
    void connectMenubarSlots();

    QSharedPointer<Ui::MainWindow> m_Ui;
};

#endif // MAINWINDOW_H
