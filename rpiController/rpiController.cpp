#include "controller.h"

using namespace rpi;

int main(int argc, char * argv[])
{
    Controller service(argc, argv);
    return service.exec();
}
