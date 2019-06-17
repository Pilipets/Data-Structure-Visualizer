#ifndef STRUCTUREREPRESENTOR_H
#define STRUCTUREREPRESENTOR_H
#include<QString>
#include "structurevisitor.h"
class StructureRepresentor{
public:
    enum class Type : int{
        SplayTree, BPlus, LinkedList, HashTable, StlList, StlMap, StlVector, RBTree
    };
    virtual void insert(const int &key, const int &value) = 0;
    virtual void remove(const int &key) = 0;
    virtual int find(const int &key) = 0;
    virtual void clear() = 0;
    virtual bool isEmpty() = 0;
    virtual void writeToFile(const char *fileName) = 0;
    inline int getType() {return (int)type;}
    virtual void accept(MyVisitor<int,int> &v) = 0;
protected:
    Type type;
};

#endif // STRUCTUREREPRESENTOR_H
