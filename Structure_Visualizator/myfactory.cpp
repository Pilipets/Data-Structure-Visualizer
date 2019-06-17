#include "myfactory.h"
#include "stllist.h"
#include "stlmap.h"
#include "splaytree.h"
#include "rbtree.h"
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
    else if(name == "SplayTree")
        res = new SplayTree<int,int>;
    else if(name == "RBTree")
        res = new RBTree<int,int>;
    return res;
}
