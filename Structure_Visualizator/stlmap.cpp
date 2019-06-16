#include "stlmap.h"
#include<fstream>
StlMap::StlMap()
{
    StructureRepresentor::type = StructureRepresentor::Type::StlMap;
}

void StlMap::insert(int key, int value)
{
    m_map[key] = value;
}

void StlMap::remove(int key)
{
    Map::const_iterator itr = m_map.find(key);
    if(itr != m_map.end()){
        m_map.erase(itr);
    }
}

void StlMap::clear()
{
    m_map.clear();
}

int StlMap::find(int key)
{
    Map::const_iterator itr = m_map.find(key);
    if(itr != m_map.end()){
        return itr->second;
    }
    else {
        return int();
    }
}

void StlMap::writeToFile(const char *fileName)
{
    std::ofstream fout(fileName);
    fout << "digraph{node[shape=record]\n" << std::endl;
    if(!m_map.empty()){
        for(const auto &elem : m_map)
        {
            fout << "      " << (quintptr)&elem;
            fout << "[label=\"";
            fout << "{key: " << elem.first << "|val:" << elem.second << "}";
            fout << "\"];" << std::endl;
        }
        fout << "\n\n";
    }

    fout << "}";
}
