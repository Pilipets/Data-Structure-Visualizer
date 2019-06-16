#include "myfactory.h"
#include "stllist.h"
#include "stlmap.h"

MyFactory *MyFactory::getInstance()
{
    static MyFactory factory;
    return &factory;
}

StructureRepresentor *MyFactory::createEssence(const QString &name)
{
    StructureRepresentor *res = nullptr;
    if(name == "StlList")
        res = new StlList;
    else if(name == "StlMap")
        res = new StlMap;
    return res;
}
