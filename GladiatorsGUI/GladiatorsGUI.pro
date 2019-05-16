#-------------------------------------------------
#
# Project created by QtCreator 2019-04-25T20:04:47
#
#-------------------------------------------------

QT       += core gui charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GladiatorsGUI
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
    connector.cpp \
    genericlinkedlist.cpp \
        main.cpp \
        display.cpp \
    genericnode.cpp \
    menu.cpp \
    netpackage.cpp \
    statistics.cpp \
    tower.cpp \
    graphpac.cpp

HEADERS += \
    connector.h \
        display.h \
    genericnode.h \
    genericlinkedlist.h \
    libraries/rapidjson/allocators.h \
    libraries/rapidjson/cursorstreamwrapper.h \
    libraries/rapidjson/document.h \
    libraries/rapidjson/encodedstream.h \
    libraries/rapidjson/encodings.h \
    libraries/rapidjson/error/en.h \
    libraries/rapidjson/error/error.h \
    libraries/rapidjson/filereadstream.h \
    libraries/rapidjson/filewritestream.h \
    libraries/rapidjson/fwd.h \
    libraries/rapidjson/internal/biginteger.h \
    libraries/rapidjson/internal/diyfp.h \
    libraries/rapidjson/internal/dtoa.h \
    libraries/rapidjson/internal/ieee754.h \
    libraries/rapidjson/internal/itoa.h \
    libraries/rapidjson/internal/meta.h \
    libraries/rapidjson/internal/pow10.h \
    libraries/rapidjson/internal/regex.h \
    libraries/rapidjson/internal/stack.h \
    libraries/rapidjson/internal/strfunc.h \
    libraries/rapidjson/internal/strtod.h \
    libraries/rapidjson/internal/swap.h \
    libraries/rapidjson/istreamwrapper.h \
    libraries/rapidjson/memorybuffer.h \
    libraries/rapidjson/memorystream.h \
    libraries/rapidjson/msinttypes/inttypes.h \
    libraries/rapidjson/msinttypes/stdint.h \
    libraries/rapidjson/ostreamwrapper.h \
    libraries/rapidjson/pointer.h \
    libraries/rapidjson/prettywriter.h \
    libraries/rapidjson/rapidjson.h \
    libraries/rapidjson/reader.h \
    libraries/rapidjson/schema.h \
    libraries/rapidjson/stream.h \
    libraries/rapidjson/stringbuffer.h \
    libraries/rapidjson/writer.h \
    menu.h \
    netpackage.h \
    statistics.h \
    tower.h \
    graphpac.h

FORMS += \
        display.ui \
    menu.ui \
    statistics.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    images.qrc

DISTFILES += \
    arena.jpg \
    arena.jpg \
    properties
