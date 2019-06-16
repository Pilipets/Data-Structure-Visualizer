#ifndef STRUCTUREREPRESENTOR_H
#define STRUCTUREREPRESENTOR_H
#include<QString>
class StructureRepresentor{
public:
    enum class Type : int{
        SplayTree, BPlus, LinkedList, HashTable, StlList, StlMap, StlVector
    };
    virtual void insert(int key, int value) = 0;
    virtual void remove(int key) = 0;
    virtual int find(int key) = 0;
    virtual void clear() = 0;
    virtual void writeToFile(const char *fileName) = 0;
    inline int getType() {return (int)type;}
protected:
    Type type;
};

#endif // STRUCTUREREPRESENTOR_H
