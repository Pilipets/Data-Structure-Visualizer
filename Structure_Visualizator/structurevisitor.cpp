#include "structurevisitor.h"
#include "stlmap.h"
#include "stllist.h"
#include "splaytree.h"
void GetItemsVisitor::visit(SplayTree *s)
{
    //const auto data =
}

void GetItemsVisitor::visit(StlList *s)
{
    const std::list<std::pair<int,int>> &data = s->data();
    amount = data.size();
    keys = std::vector<int>(amount);
    values = std::vector<int>(amount);

    int index = 0;
    for(const auto &item: data){
        keys[index] = item.first;
        values[index] = item.second;
        index += 1;
    }
}

void GetItemsVisitor::visit(StlMap *s)
{
    const std::map<int,int> &data = s->data();
    amount = data.size();
    keys = std::vector<int>(amount);
    values = std::vector<int>(amount);

    int index = 0;
    for(const auto &item: data){
        keys[index] = item.first;
        values[index] = item.second;
        index += 1;
    }
}
