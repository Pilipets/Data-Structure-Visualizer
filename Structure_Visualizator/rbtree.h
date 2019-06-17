#ifndef STATISTICRBTREE_H
#define STATISTICRBTREE_H
#include<utility>
#include "structurerepresentor.h"
template<typename Key, typename T>
class RBTree : public StructureRepresentor
{
public:
    struct Node
    {
        Key key;
        T value;
        int size;
        bool color;
        Node *left, *right, *parent;
        // Constructor
        Node() : color(BLACK),size(0), key(), value(){
            left = parent = right = nullptr;
        }
        Node(const Key &key, const T &val):Node(){
            this->key = key; this->value = val;
        }
    };
    Node* nil = new Node();
private:
    enum Color { RED, BLACK };
    Node *root;

    void _RotateLeft(Node* x);
    void _RotateRight(Node* x);
    void _fixRank(Node *x);

    void _DeleteBST(Node *z);
    void _fixDeleteRBTree(Node *x);
    Node* _SearchBST(Node* tree, const Key &toSearch);
    void _fixInsertRBTree(Node *x);
    void _InsertBST(Node* &tree, Node* toInsert);
public:
    RBTree();
    ~RBTree();

    bool isEmpty() {return root == nil; }
    void insert(const Key & key, const T &val) override;
    void remove(const Key &key) override;
    T find(const Key & key) override;
    void clear() override;
    void writeToFile(const char *fileName) override;
    const Node* data() const{return root;}
    void accept(MyVisitor<Key,T> &v) override;
};

#endif // STATISTICRBTREE_H
