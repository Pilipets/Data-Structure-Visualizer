#ifndef REDBLACKTREE_H
#define REDBLACKTREE_H
#include "structurerepresentor.h"
enum Color { RED, BLACK };

struct Node
{
    int key;
    int value;
    bool color;
    Node *left, *right, *parent;
    int size;
    // Constructor
    Node(const int &key, const int &value) : size(0)
    {
        this->key = key;
        this->value = value;
        left = right = parent = nullptr;
        color = RED;
    }
};
class RB_Tree: public StructureRepresentor
{
private:
    Node *root;
    int _getColor(Node * node);
    void _setColor(Node* node, int color);
    Node* _Tree_Successor(Node *root);
    void _RotateLeft(Node* &tree, Node* pt);
    void _RotateRight(Node* &tree, Node* pt);

    Node* _SearchBST(Node* tree, const int &key);
    void _fixInsertRBTree(Node* &tree, Node *&pt);
    void _fixDeleteRBTree(Node* &tree, Node *&pt);
    void _InsertBST(Node* tree, Node* toInsert);
    Node* _DeleteBST(Node* tree, Node* toDelete);


public:
    RB_Tree();
    ~RB_Tree();

    bool isEmpty() override {return root == nullptr;}
    int find(const int& data) override;
    void insert(const int& key, const int& data) override;
    void remove(const int& key) override;
    void writeToFile(const char *fileName) override;
    void clear() override;
};
#endif // REDBLACKTREE_H
