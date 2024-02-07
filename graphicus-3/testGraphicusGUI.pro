TEMPLATE     = vcapp
TARGET       = testGraphicusGUI
CONFIG      += warn_on qt debug windows console
HEADERS     += monInterface.h 
SOURCES     += testGraphicusGUI.cpp monInterface.cpp
INCLUDEPATH += ../graphicus-lib
LIBS        += ../graphicus-lib/graphicusGUI.lib
QT          += widgets
