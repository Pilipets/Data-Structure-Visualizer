#ifndef SETALGORITHMS_H
#define SETALGORITHMS_H

class StructureRepresentor;
template<class K, class V> class RBTree;
template<class K, class V> class SplayTree;
class StlList;
class StlMap;

class SetAlgorithms{
private:
    template<class K,class V>
    void saveIntersection(StructureRepresentor *s, StructureRepresentor* s1, StructureRepresentor *s2);
    template<class K,class V>
    void saveUnion(StructureRepresentor *s, StructureRepresentor* s1, StructureRepresentor *s2);
public:
    enum class OperationType: int{Intersection, Union, Difference};
    StructureRepresentor *getIntersection(StructureRepresentor* s1, StructureRepresentor *s2);
    StructureRepresentor *getUnion(StructureRepresentor* s1, StructureRepresentor *s2);
};


#endif // SETALGORITHMS_H
