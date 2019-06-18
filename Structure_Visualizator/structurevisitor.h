#ifndef STRUCTUREVISITOR_H
#define STRUCTUREVISITOR_H
#include<vector>

template<class K, class V> class RBTree;
template<class K, class V> class SplayTree;
class StlList;
class StlMap;

template<class K, class V>
class MyVisitor{
public:
    virtual void visit(RBTree<K,V> *s) = 0;
    virtual void visit(SplayTree<K,V> *s) = 0;
    virtual void visit(StlList * s) = 0;
    virtual void visit(StlMap * s) = 0;
    virtual ~MyVisitor() = default;
    MyVisitor() = default;
};

template<class K, class V>
class GetItemsVisitor : public MyVisitor<K,V>{
public:
    std::vector<K> keys;
    std::vector<V> values;
    size_t amount;
    GetItemsVisitor();
public:
    void visit(RBTree<K,V> *s) override;
    void visit(SplayTree<K,V> *s) override;
    void visit(StlList * s) override;
    void visit(StlMap * s) override;
};


#endif // STRUCTUREVISITOR_H
