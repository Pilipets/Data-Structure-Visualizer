#ifndef SPLAYTREE_H
#define SPLAYTREE_H

#include<fstream>
#include<string>
#include<utility>
#include "structurerepresentor.h"

using std::pair;
using std::string;
using std::ofstream;
template<typename T, typename _Val>
struct SplayNode
{
    T key;
    _Val value;
    SplayNode *left, *right;
    SplayNode(const T &key, const _Val& value)
    {
        this->key = key;
        this->value = value;
        left = right = nullptr;
    }
    SplayNode(const pair<T,_Val> &value) : SplayNode(value.first, value.second)
    {}
};

template<typename T, typename _Val>
class SplayTree : public StructureRepresentor
{
    using Node = SplayNode<T,_Val>;
private:
    void bst_print_dot_aux(Node* node, ofstream& stream);

    Node *rightRotate(Node *y);
    Node *leftRotate(Node *x);

    Node *splay(Node *root, const T &key);

    Node *search(Node *root, const T &key);
    Node *insert(Node *root, const pair<T, _Val> &value);
    Node* delete_key(Node *root, const T &key);


    void print_tree(Node* root, int shift);
    void freeMemory(Node * root);
    Node* tree;
public:
    SplayTree();
    ~SplayTree();

    bool isEmpty() override{return tree == nullptr; }
    void insert(const T &key, const _Val &value) override;
    void remove(const T &key) override;
    void clear() override;
    _Val find(const T &key) override;
    void writeToFile(const char *fileName) override;
    const Node * data() const {return  tree; }
};


#endif // SPLAYTREE_H
