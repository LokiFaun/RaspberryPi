#RaspberryPi

Homeautomation using Raspberry Pi with a temperature and luminance sensor.

##Dependencies:
- QtSolutions - QtService (https://qt.gitorious.org/qt-solutions)
- QtJsonSettings (https://gitorious.org/qtjsonsettings)
- Poco v1.4.7 (http://pocoproject.org/)
- QsLog (https://bitbucket.org/razvanpetru/qslog)
- WiringPi (http://wiringpi.com/)

##Directory Structure
The following directory structure is used by the projects using relative paths:
- BaseDir
  - Poco
  - QtSolutions
  - QtJsonSettings
  - QsLog
  - RaspberryPi
  - WiringPi

##Contains
- rpiBase: library with basic classes, functions and definitions
- rpiConfig: library with configuration classes and funktions
- rpiLogger: library with logging classes and functions
- rpiServiceMonitor: a background service which checks that the needed services are up and running
- rpiController: a background service retrieving inputs and controlling outputs accordingly
- rpiConfigurator: Qt4 application to manipulate configuration files for the services
