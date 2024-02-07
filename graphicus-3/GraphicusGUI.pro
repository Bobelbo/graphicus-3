TEMPLATE     = vcapp
TARGET       = Graphicus-03
CONFIG      += warn_on qt debug windows console
HEADERS     += monInterface.h $$files(../graphicus-2/*.h)
SOURCES     += testGraphicusGUI.cpp monInterface.cpp $$files(../graphicus-2/*.cpp)
INCLUDEPATH += ../graphicus-lib
LIBS        += ../graphicus-lib/graphicusGUI.lib
QT          += widgets
