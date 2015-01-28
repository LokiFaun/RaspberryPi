#include "controller.h"

int main(int argc, char *argv[])
{
    Controller service(argc, argv);
    return service.exec();
}
