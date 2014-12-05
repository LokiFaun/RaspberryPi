win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../poco-1.4.7p1/lib/MinGW/ia32 -lPocoFoundation -lPocoNet
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../poco-1.4.7p1/lib/MinGW/ia32 -lPocoFoundationd -lPocoNetd
else:unix:CONFIG(release, debug|release): LIBS += -lPocoFoundation -lPocoNet
else:unix:CONFIG(debug, debug|release): LIBS += -lPocoFoundationd -lPocoNetd

INCLUDEPATH += $$OUT_PWD/../../poco-1.4.7p1/include
DEPENDPATH += $$OUT_PWD/../../poco-1.4.7p1/include