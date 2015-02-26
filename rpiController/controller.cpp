#include "controller.h"
#include <name_defs.h>
#include "../rpiConfig/controllerconfiguration.h"
#include <logmanager.h>
#include <container.h>

#include <QStringList>
#include <QFile>

using namespace rpi;

Controller::Controller(int argc, char ** argv) : QtService<QCoreApplication>(argc, argv, "rpiController")
{
    m_pContainer = QSharedPointer<Container>(new Container);
    load(argc, argv);
}

Controller::~Controller()
{
}

void Controller::start()
{
    RPI_DEBUG("rpiController", QString("starting service"));
    ControllerConfiguration * pConfig = m_pContainer->getObject<ControllerConfiguration>();
    if (pConfig != NULL)
    {
    }
}

void Controller::stop()
{
}

void Controller::processCommand(int /*code*/)
{
}

void Controller::load(int argc, char ** argv)
{
    QStringList args;
    for (int i = 1; i < argc; ++i)
    {
        args.push_back(argv[i]);
    }

    RPI_DEBUG("rpiController", QString("loading service with arguments: ") + args.join(" "));

    QString fileName;
    // parse command line arguments
    for (QStringList::ConstIterator iter = args.constBegin(); iter != args.constEnd(); ++iter)
    {
        if (iter->compare("-config", Qt::CaseInsensitive) == 0)
        {
            ++iter;
            fileName = *iter;
        }
    }
    // check if passed file exists, set default file if not
    if (fileName.isEmpty() || !QFile::exists(fileName))
    {
        fileName = DefaultControllerConfigFile;
    }

    // load configuration if the file exists
    if (QFile::exists(fileName))
    {
        ControllerConfiguration * pConfig = new ControllerConfiguration(fileName);
        m_pContainer->registerObject(pConfig);
    }
}
