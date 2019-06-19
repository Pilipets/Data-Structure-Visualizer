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

StructureRepresentor *MyFactory::createEssence(StructureRepresentor *s1)
{
    StructureRepresentor *res = nullptr;
    if(dynamic_cast<RBTree<int,int>*>(s1)){
        res = new RBTree<int,int>;
    }
    else if(dynamic_cast<SplayTree<int,int>*>(s1)){
        res = new SplayTree<int,int>;
    }
    else if(dynamic_cast<StlList*>(s1)){
        res = new StlList;
    }
    else if(dynamic_cast<StlMap*>(s1)){
        res = new StlMap;
    }
    return res;
}
