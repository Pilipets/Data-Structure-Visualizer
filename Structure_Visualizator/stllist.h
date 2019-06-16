#ifndef STLLIST_H
#define STLLIST_H
#include "structurerepresentor.h"
#include <list>
#include <utility>


class StlList: public StructureRepresentor{
private:
    using List = std::list<std::pair<int,int>>;
public:
    StlList();
    ~StlList();
    void insert(int key, int value) override;
    void remove(int key) override;
    int find(int key) override;
    void writeToFile(const char *fileName) override;
private:
    List m_list;


};

#endif // STLLIST_H
