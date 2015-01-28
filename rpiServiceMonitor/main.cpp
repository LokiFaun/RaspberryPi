#include "servicemonitor.h"

using namespace rpi;

int main(int argc, char **argv)
{
    ServiceMonitor service(argc, argv);
    return service.exec();
}
