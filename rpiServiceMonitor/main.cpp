#include "servicemonitor.h"
#include "QtServiceController"
#include "logmanager.h"

#include <QDir>

using namespace rpi;

int main(int argc, char **argv)
{
    ServiceMonitor service(argc, argv);
    return service.exec();
}
