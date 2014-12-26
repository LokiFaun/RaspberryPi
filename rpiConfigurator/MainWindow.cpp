#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QMessageBox>
#include <QLayout>

#include "servicemonitorconfiguration.h"
#include "logmanager.h"

using namespace rpi;

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
    connect(m_Ui->actionSave, SIGNAL(triggered()), this, SLOT(saveConfiguration()));
    connect(m_Ui->actionSaveAll, SIGNAL(triggered()), this, SLOT(saveAllConfigurations()));
    connect(m_Ui->actionAboutQt, SIGNAL(triggered()), this, SLOT(aboutQt()));
    connect(m_Ui->actionQuit, SIGNAL(triggered()), this, SLOT(closeWindow()));
}

void MainWindow::newConfiguration()
{

}

void MainWindow::saveConfiguration()
{
    RPI_DEBUG("rpiConfigurator", "saving current configuration");
    const int idx = m_TabWidget->currentIndex();
    IConfigurationWidget *pWidget = dynamic_cast<IConfigurationWidget *>(m_TabWidget->currentWidget());
    if (pWidget == NULL)
    {
        RPI_WARN(Q_FUNC_INFO, "invalid tab-widget");
        return;
    }
    pWidget->saveConfiguration();
    QString name = m_TabWidget->tabText(idx);
    if (name.endsWith("*"))
    {
        RPI_DEBUG(Q_FUNC_INFO, "setting new tab-text");
        name.resize(name.count() - 1);
        m_TabWidget->setTabText(idx, name);
    }
}

void MainWindow::saveAllConfigurations()
{
    RPI_DEBUG("rpiConfigurator", "saving all configurations");
    const int count = m_TabWidget->count();
    for (int idx = 0; idx < count; idx++)
    {
        IConfigurationWidget *pWidget = dynamic_cast<IConfigurationWidget *>(m_TabWidget->widget(idx));
        if (pWidget == NULL)
        {
            RPI_WARN("rpiConfigurator", "invalid tab-widget");
            continue;
        }
        pWidget->saveConfiguration();
        QString name = m_TabWidget->tabText(idx);
        if (name.endsWith("*"))
        {
            RPI_DEBUG("rpiConfigurator", "setting new tab-text");
            name.resize(name.count() - 1);
            m_TabWidget->setTabText(idx, name);
        }
    }
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
    const QString fileName = "/tmp/test.json";
    IConfigurationWidget * pWidget = m_TabFactory->createConfigurationTab(Configuration::ServiceMonitor, new ServiceMonitorConfiguration(fileName));
    connect(pWidget, SIGNAL(configurationChanged()), this, SLOT(handleConfigurationChanged()));
    connect(pWidget, SIGNAL(configurationSaved()), this, SLOT(handleConfigurationSaved()));

    m_TabWidget->addTab(pWidget, fileName);
    connect(m_TabWidget, SIGNAL(tabCloseRequested(int)), this, SLOT(closeTab(int)));

    QMainWindow::setCentralWidget(m_TabWidget);    
}

void MainWindow::handleConfigurationChanged()
{
    RPI_DEBUG("rpiConfigurator", "configuration has changed");
    const int idx = m_TabWidget->currentIndex();
    const QString name = m_TabWidget->tabText(idx);
    if (!name.endsWith("*"))
    {
        RPI_DEBUG(Q_FUNC_INFO, "setting new tab-text");
        m_TabWidget->setTabText(idx, name + "*");
    }
}

void MainWindow::handleConfigurationSaved()
{
    RPI_DEBUG("rpiConfigurator", "configuration has been saved");
    const int idx = m_TabWidget->currentIndex();
    QString name = m_TabWidget->tabText(idx);
    if (name.endsWith("*"))
    {
        RPI_DEBUG("rpiConfigurator", "setting new tab-text");
        name.resize(name.count() - 1);
        m_TabWidget->setTabText(idx, name);
    }
}

void MainWindow::closeTab(int id)
{
    m_TabWidget->removeTab(id);
}
