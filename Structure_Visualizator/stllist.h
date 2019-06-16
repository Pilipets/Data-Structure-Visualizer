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
    void insert(const int &key, const int &value) override;
    void remove(const int &key) override;
    void clear() override;
    int find(const int &key) override;
    bool isEmpty() override{return m_list.empty();}
    void writeToFile(const char *fileName) override;
private:
    List m_list;
};

#endif // STLLIST_H
