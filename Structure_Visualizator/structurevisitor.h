#ifndef STRUCTUREVISITOR_H
#define STRUCTUREVISITOR_H
#include<vector>
class RBTree;
class SplayTree;
class StlList;
class StlMap;
class MyVisitor{
public:
    virtual void visit(RBTree *s) = 0;
    virtual void visit(SplayTree *s) = 0;
    virtual void visit(StlList * s) = 0;
    virtual void visit(StlMap * s) = 0;
    virtual ~MyVisitor() = default;
};

class GetItemsVisitor : public MyVisitor{
public:
    std::vector<int> keys, values;
    size_t amount;
public:
    void visit(RBTree *s) override;
    void visit(SplayTree *s) override;
    void visit(StlList * s) override;
    void visit(StlMap * s) override;
};


#endif // STRUCTUREVISITOR_H
