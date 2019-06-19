CONFIG+=console c++1z

INCLUDEPATH+="googletest/include"
INCLUDEPATH+="googletest/"
INCLUDEPATH+="../../Structure_Visualizator/"
SOURCES += \
    main.cpp \
    googletest/src/gtest-all.cc

HEADERS += \
    ../../Structure_Visualizator/stlmap.h \
    ../../Structure_Visualizator/stllist.h \
    ../../Structure_Visualizator/splaytree.h \
    ../../Structure_Visualizator/rbtree.h \
    ../../Structure_Visualizator/myfactory.h\
    ../../Structure_Visualizator/structurerepresentor.h \
    ../../Structure_Visualizator/structurevisitor.h

SOURCES += \
    ../../Structure_Visualizator/stlmap.cpp \
    ../../Structure_Visualizator/stllist.cpp \
    ../../Structure_Visualizator/splaytree.cpp \
    ../../Structure_Visualizator/rbtree.cpp \
    ../../Structure_Visualizator/myfactory.cpp\
    ../../Structure_Visualizator/structurevisitor.cpp
