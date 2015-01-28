#include "controller.h"


Controller::Controller(int argc, char **argv) : QtService<QCoreApplication>(argc, argv, "rpiController")
{
}


Controller::~Controller() { }

void Controller::start() { }

void Controller::stop() { }

void Controller::processCommand(int /*code*/) { }
