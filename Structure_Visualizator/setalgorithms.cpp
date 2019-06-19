#include "setalgorithms.h"
#include "myfactory.h"
#include "rbtree.h"
#include "myfactory.h"
#include "structurevisitor.h"
#include "stllist.h"
#include "stlmap.h"
#include "splaytree.h"

StructureRepresentor *SetAlgorithms::getIntersection(StructureRepresentor *s1, StructureRepresentor *s2)
{
    StructureRepresentor *s = MyFactory::getInstance()->createEssence(s1);
    this->saveIntersection<int,int>(s,s1,s2);
    return s;
}

StructureRepresentor *SetAlgorithms::getUnion(StructureRepresentor *s1, StructureRepresentor *s2)
{
    StructureRepresentor *s = MyFactory::getInstance()->createEssence(s1);
    this->saveUnion<int,int>(s,s1,s2);
    return s;
}

template<class K, class V>
void SetAlgorithms::saveIntersection(StructureRepresentor *s, StructureRepresentor *s1, StructureRepresentor *s2)
{
    GetItemsVisitor<int,int> v1,v2;
    s1->accept(v1),s2->accept(v2);
    for(size_t i = 0; i < v1.amount; ++i){
        auto it2 = std::find(v2.keys.begin(),v2.keys.end(),v1.keys[i]);
        if(it2 != v2.keys.end() && v1.values[i] == v2.values[std::distance(it2,v2.keys.begin())])
            s->insert(v1.keys[i],v1.values[i]);
    }
}

template<class K, class V>
void SetAlgorithms::saveUnion(StructureRepresentor *s, StructureRepresentor *s1, StructureRepresentor *s2)
{
    GetItemsVisitor<int,int> v1,v2;
    s1->accept(v1),s2->accept(v2);
    for(size_t i = 0; i < v1.amount; ++i){
        s->insert(v1.keys[i],v1.values[i]);
    }
    for(size_t i = 0; i < v2.amount; ++i){
        s->insert(v2.keys[i],v2.values[i]);
    }
}
