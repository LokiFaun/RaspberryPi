#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    m_Ui(new Ui::MainWindow)
{
    m_Ui->setupUi(this);

    connectMenubarSlots();
}

MainWindow::~MainWindow() { }

void MainWindow::aboutQt()
{
    QMessageBox::aboutQt(this, "rpiConfigurator");
}

void MainWindow::connectMenubarSlots()
{
    connect(m_Ui->actionAboutQt, SIGNAL(triggered()), this, SLOT(aboutQt()));
    connect(m_Ui->actionQuit, SIGNAL(triggered()), this, SLOT(closeWindow()));
}

void MainWindow::newConfiguration()
{

}

void MainWindow::saveConfiguration()
{

}

void MainWindow::openConfiguration()
{

}

void MainWindow::closeWindow()
{
    close();
}
