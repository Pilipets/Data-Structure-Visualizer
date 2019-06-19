#-------------------------------------------------
#
# Project created by QtCreator 2019-06-15T15:15:09
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Structure_Visualizator
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

CONFIG += c++14

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    stllist.cpp \
    corefacade.cpp \
    drawer.cpp \
    stlmap.cpp \
    myfactory.cpp \
    splaytree.cpp \
    insertonedialog.cpp \
    rbtree.cpp \
    structurevisitor.cpp \
    propertiesdialog.cpp \
    setalgorithms.cpp \
    setoperationsdialog.cpp \
    settingsdialog.cpp \
    myrandom.cpp

HEADERS += \
        mainwindow.h \
    structurerepresentor.h \
    stllist.h \
    corefacade.h \
    drawer.h \
    stlmap.h \
    myfactory.h \
    splaytree.h \
    insertonedialog.h \
    rbtree.h \
    structurevisitor.h \
    propertiesdialog.h \
    setalgorithms.h \
    setoperationsdialog.h \
    settingsdialog.h \
    myrandom.h

FORMS += \
        mainwindow.ui \
    insertonedialog.ui \
    propertiesdialog.ui \
    setoperationsdialog.ui \
    settingsdialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
