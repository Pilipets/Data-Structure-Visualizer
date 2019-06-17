#include "stllist.h"
#include<algorithm>
#include <fstream>

StlList::StlList()
{
    StructureRepresentor::type = StructureRepresentor::Type::StlList;
}

StlList::~StlList()
{}

void StlList::insert(const int &key, const int &value)
{
    List::iterator itr = std::find_if(m_list.begin(), m_list.end(),
                                        [key](const std::pair<int,int> &elem){
             return elem.first == key;});
    if(itr != m_list.end())
        itr->second = value;
    else {
        m_list.emplace_front(key,value);
    }

}

void StlList::remove(const int &key)
{
    List::const_iterator itr = std::find_if(m_list.begin(), m_list.end(),
                                   [key](const std::pair<int,int> &elem){
        return elem.first == key;});
    if(itr != m_list.end()){
        m_list.erase(itr);
    }
}

void StlList::clear()
{
    m_list.clear();
}

int StlList::find(const int &key)
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

void StlList::writeToFile(const char *fileName)
{
    std::ofstream fout(fileName);
    fout << "digraph{node[shape=record]\n" << std::endl;

    if(!m_list.empty()){
        for(const auto &elem : m_list)
        {
            fout << "      " << (quintptr)&elem;
            fout << "[label=\"";
            fout << "{key: " << elem.first << "|val:" << elem.second << "}";
            fout << "\"];" << std::endl;
        }
        fout << "\n\n";

        fout << (quintptr)&(*m_list.begin());
        for(auto itr = ++m_list.begin(); itr != m_list.end(); ++itr)
        {
            fout << "->" << (quintptr)&(*itr) << ";\n";
            fout << (quintptr)&(*itr);
        }
        fout << "->end;\n";
    }
    fout << "}";
}

void StlList::accept(MyVisitor<int, int> &v)
{
    v.visit(this);
}

