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
    void insert(const int &key, const int &value) override;
    void remove(const int &key) override;
    void clear() override;
    int find(const int &key) override;
    bool isEmpty() override {return m_map.empty();}
    void writeToFile(const char *fileName) override;
    const Map& data() const {return m_map;}
private:
    Map m_map;
};
#endif // STLMAP_H
