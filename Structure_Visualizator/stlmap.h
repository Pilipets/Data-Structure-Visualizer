#ifndef STLMAP_H
#define STLMAP_H

#include "structurerepresentor.h"
#include <map>
#include <utility>

class StlMap: public StructureRepresentor{
private:
    using Map = std::map<int,int>;
public:
    StlMap();
    ~StlMap() = default;
    void insert(int key, int value) override;
    void remove(int key) override;
    void clear() override;
    int find(int key) override;
    void writeToFile(const char *fileName) override;
private:
    Map m_map;
};
#endif // STLMAP_H
