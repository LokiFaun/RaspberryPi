#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QMessageBox>
#include <QLayout>

#include "servicemonitorconfiguration.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    m_Ui(new Ui::MainWindow)
{
    m_Ui->setupUi(this);
    m_TabFactory.create();

    connectMenubarSlots();
    createTabWidget();
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

void MainWindow::createTabWidget()
{
    m_TabWidget = new QTabWidget;
    m_TabWidget->setDocumentMode(true);
    m_TabWidget->setTabsClosable(true);

    // TODO: remove
    m_TabWidget->addTab(m_TabFactory->createConfigurationTab(Configuration::ServiceMonitor, new ServiceMonitorConfiguration("test.json")), "Test");

    connect(m_TabWidget, SIGNAL(tabCloseRequested(int)), this, SLOT(closeTab(int)));
    QMainWindow::setCentralWidget(m_TabWidget);    
}

void MainWindow::closeTab(int id)
{
    m_TabWidget->removeTab(id);
}
