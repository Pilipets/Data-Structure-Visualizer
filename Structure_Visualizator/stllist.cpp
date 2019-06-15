#include "stllist.h"
#include<algorithm>
StlList::StlList()
{
    StructureRepresentor::type = StructureRepresentor::Type::StlList;
}

void StlList::insert(int key, int value)
{
    m_list.emplace_front(key,value);
}

void StlList::remove(int key)
{
    List::const_iterator itr = std::find_if(m_list.begin(), m_list.end(),
                                   [key](const std::pair<int,int> &elem){
        return elem.first == key;
    });
    if(itr != m_list.end()){
        m_list.erase(itr);
    }
}

int StlList::find(int key)
{
    List::const_iterator itr = std::find_if(m_list.begin(), m_list.end(),
                                   [key](const std::pair<int,int> &elem){
        return elem.first == key;
    });
    if(itr != m_list.end()){
        return itr->second;
    }
    else {
        return int();
    }
}

