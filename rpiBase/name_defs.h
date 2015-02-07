#ifndef NAME_DEFS_H
#define NAME_DEFS_H

#pragma once

namespace rpi
{

    const QString DefaultMonitorConfigFile("/home/user/pi/.rpi/monitorConfig.json");
    const QString DefaultControllerConfigFile("/home/user/pi/.rpi/controllerConfig.json");

    const QString DefaultLoggingFilename("/home/user/pi/.rpi/log.log");
    const QString DefaultLoggingLevel = "level";
    const int DefaultLoggingFileSize = 5 * 1024 * 1024;
    const int DefaultLoggingFileCount = 1;

    const bool DefaultAutodimmingEnabled = false;
    const unsigned int DefaultAutodimmingMinValue = 100;
    const unsigned int DefaultAutodimmingMaxValue = 5000;
    const unsigned int DefaultAutodimmingMinBrightness = 1;
    const unsigned int DefaultAutodimmingMaxBrightness = 99;
    const unsigned int DefaultAutodimmingUpdateIntervall = 2000;

    const bool DefaultTemperatureMonitorEnabled = false;
    const unsigned int DefaultTemperatureMonitorUpdateIntervall = 2000;

    const bool DefaultServiceMonitorEnabled = false;
    const QString DefaultServiceMonitor = "rpiServiceMonitor";
    const unsigned int DefaultServiceMonitorUpdateIntervall = 5000;

}

#endif // NAME_DEFS_H
