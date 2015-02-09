#include "controller.h"
#include <name_defs.h>
#include "../rpiConfig/controllerconfiguration.h"
#include <logmanager.h>
#include <container.h>
#include <publisher.h>

#include <QStringList>

using namespace rpi;

Controller::Controller(int argc, char **argv) : QtService<QCoreApplication>(argc, argv, "rpiController")
{
    m_pContainer = QSharedPointer<Container>(new Container);
    load(argc, argv);
}

Controller::~Controller() { }

void Controller::start()
{
    RPI_DEBUG("rpiController", QString("starting service"));
    ControllerConfiguration * pConfig = m_pContainer->getObject<ControllerConfiguration>();
    if (pConfig != NULL)
    {
    }
}

void Controller::stop() { }

void Controller::processCommand(int /*code*/) { }

void Controller::load(int argc, char** argv)
{
    QStringList args;
    for (int i = 1; i < argc; ++i)
    {
        args.push_back(argv[i]);
    }

    RPI_DEBUG("rpiController", QString("loading service with arguments: ") + args.join(" "));
    QString fileName = DefaultControllerConfigFile;

    for (int i = 0; i < argc - 1; ++i)
    {
        QString id(argv[i]);
        QString arg(argv[i + 1]);

        if (id.compare("-config", Qt::CaseInsensitive) == 0)
        {
            fileName = arg;
        }
    }

    ControllerConfiguration * pConfig = new ControllerConfiguration(fileName);
    m_pContainer->registerObject(pConfig);
}