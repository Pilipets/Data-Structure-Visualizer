#include "rbtree.h"
#include <iomanip>
#include<string>
#include<stack>
#include<fstream>
#include<queue>

template class RBTree<int,int>;
template<typename Key, typename T> void RBTree<Key, T>::_RotateLeft(Node * x)
{
    Node* y = x->right;

    x->right = y->left;//x->right = x->right->left
    if (y->left != nil)y->left->parent = x;//x->right->left parent now x

    y->parent = x->parent;//x->right's parent is now x's parent
    if (x->parent == nil)
        root = y;
    else if (x == x->parent->left)
        x->parent->left = y;
    else
        x->parent->right = y;


    y->left = x;//x->right->left = parent
    x->parent = y;//x's parent now right

    y->size = x->size;
    x->size = x->left->size + x->right->size + 1;
}
template<typename Key, typename T> void RBTree<Key, T>::_RotateRight(Node * x)
{
    Node* y = x->left;

    x->left = y->right;//x->left = x->left->right
    if (y->right != nil)
        y->right->parent = x;//x->left->right parent now x

    y->parent = x->parent;//x->left's parent is now x's parent
    if (x->parent == nil)
        root = y;
    else if (x == x->parent->right)
        x->parent->right = y;
    else
        x->parent->left = y;

    y->right = x;//x->left->right = parent
    x->parent = y;//x's parent now left

    y->size = x->size;
    x->size = x->left->size + x->right->size + 1;
}

template<typename Key, typename T> void RBTree<Key, T>::_fixRank(Node * x)
{
    Node* temp = x;
    while (temp != nil)
    {
        temp->size -= 1;
        temp = temp->parent;
    }
}


template<typename Key, typename T> void RBTree<Key, T>::_DeleteBST(Node * z)
{
    Node *x, *y;
    //if (!z || z == nil) return;
    if (z->left == nil || z->right == nil) {
        /* y has a NIL node as a child */
        y = z;
    }
    else {
        /* find tree successor with a NIL node as a child */
        y = z->right;
        y->size -= 1;
        while (y->left != nil) y = y->left, y->size -= 1;
    }
    /* x is y's only child */
    if (y->left != nil)
        x = y->left;
    else
        x = y->right;
    /* remove y from the parent chain */
    x->parent = y->parent;
    if (y->parent == nil)
        root = x;
    else{
        if (y == y->parent->left)
            y->parent->left = x;
        else
            y->parent->right = x;
    }

    if (y != z) {
        z->key = y->key;
        z->value = y->value;
    }
    if (y->color == BLACK)
        _fixDeleteRBTree(x);
    delete y;
}

template<typename Key, typename T> void RBTree<Key, T>::_fixDeleteRBTree(Node * x)
{
    //if (x == nullptr)return;
    while (x != root && x->color == BLACK)
    {
        if (x == x->parent->left)
        {
            Node* w = x->parent->right;//brother on the right
            if (w->color == RED)//case (brother is red)
            {
                w->color = BLACK;
                x->parent->color = RED;
                _RotateLeft(x->parent);
                w = x->parent->right;
            }
            if (w->left->color == BLACK && w->right->color == BLACK) //brother is black and both children are black
            {
                w->color = RED;//make brother red
                x = x->parent;//continue with father if black
            }
            else
            {
                if (w->right->color == BLACK) //case black brother on the right and red child on the left
                {
                    w->left->color = BLACK;
                    w->color = RED;
                    _RotateRight(w);
                    w = x->parent->right;
                }
                //continue with case black brother on the right and red child on the right
                w->color = x->parent->color;
                x->parent->color = BLACK;
                w->right->color = BLACK;
                _RotateLeft(x->parent);
                x = root;
            }
        }
        else
        {
            Node* w = x->parent->left;//brother on the left
            if (w->color == RED) //case (brother is red)
            {
                w->color = BLACK;
                x->parent->color = RED;
                _RotateRight(x->parent);
                w = x->parent->left;
            }
            if (w->right->color == BLACK && w->left->color == BLACK) //brother is black and both children are black
            {
                w->color = RED;//make brother red
                x = x->parent;//continue with father
            }
            else
            {
                if (w->left->color == BLACK) //case black brother on the left and red child on the right
                {
                    w->right->color = BLACK;
                    w->color = RED;
                    _RotateLeft(w);
                    w = x->parent->left;
                }
                //continue with case black brother on the left and red child on the left
                w->color = x->parent->color;
                x->parent->color = BLACK;
                w->left->color = BLACK;
                _RotateRight(x->parent);
                x = root;
            }
        }
    }
    x->color = BLACK;
}

template<typename Key, typename T>
typename RBTree<Key, T>::Node * RBTree<Key, T>::_SearchBST(Node * tree, const Key &toSearch)
{
    Node* current = tree;
    while (current != nil)
    {
        if (toSearch == current->key)
            return current;
        else
            current = (toSearch < current->key) ? current->left : current->right;
    }
    return nullptr;
}

template<typename Key, typename T> void RBTree<Key, T>::_fixInsertRBTree(Node *x)
{
    while (x->parent->color == RED)
    {
        if (x->parent == x->parent->parent->left)//if new element's parent to the left then uncle to the right
        {
            Node* y = x->parent->parent->right;//uncle to the right
            if (y->color == RED)//2nd case (recolour parent, grandparent, and uncle)
            {
                x->parent->color = BLACK;
                y->color = BLACK;
                x->parent->parent->color = RED;
                x = x->parent->parent;
            }
            else //if uncle is black
            {
                if (x == x->parent->right)//3rd case (rotate parent in the opposite direction of new elem)
                {
                    x = x->parent;
                    _RotateLeft(x);
                }
                //4th case (rotate grandparent in the opposite direction of our elem, recolour parent and grandparent)
                x->parent->color = BLACK;
                x->parent->parent->color = RED;
                _RotateRight(x->parent->parent);
            }
        }
        else//if new element's parent to the right then uncle to the left
        {
            Node* y = x->parent->parent->left;
            if (y->color == RED)//2nd case (recolour parent, grandparent, and uncle)
            {
                x->parent->color = BLACK;
                y->color = BLACK;
                x->parent->parent->color = RED;
                x = x->parent->parent;
            }
            else //if uncle is black
            {
                if (x == x->parent->left)//3rd case (rotate parent in the opposite direction of new elem)
                {
                    x = x->parent;
                    _RotateRight(x);
                }
                //4th case (rotate grandparent in the opposite direction of our elem, recolour parent and grandparent)
                x->parent->color = BLACK;
                x->parent->parent->color = RED;
                _RotateLeft(x->parent->parent);
            }
        }
    }
    root->color = BLACK;//first case
}

template<typename Key, typename T> void RBTree<Key, T>::_InsertBST(Node *& tree, Node * toInsert)
{
    Node *toInsert_parent = nil;
    Node *current = tree;

    while (current != nil)
    {
        toInsert_parent = current;
        current->size += 1;
        current = (toInsert->key < current->key) ? current->left : current->right;
    }
    toInsert->parent = toInsert_parent;

    if (toInsert_parent == nil)
        tree = toInsert;
    else if (toInsert->key < toInsert_parent->key)
        toInsert_parent->left = toInsert;
    else
        toInsert_parent->right = toInsert;
}


// Function to insert a new node with given data
template<typename Key, typename T> void RBTree<Key, T>::insert(const Key &key, const T &value)
{
    //insert node as leaf into right place, colour it red, invoke _fixInsertRBTree
    Node *pt = new Node(key,value);
    pt->color = RED;
    pt->left = pt->right = pt->parent = nil;
    pt->size = 1;

    // Do a normal BST insert
    _InsertBST(root, pt);

    // fix Red Black Tree violations
    _fixInsertRBTree(pt);
}
template<typename Key, typename T> void RBTree<Key, T>::remove(const Key &data)
{
    Node *x = _SearchBST(root, data);

    if (x != nullptr) {
        _fixRank(x);
        _DeleteBST(x);
    }
}

template<typename Key, typename T>
T RBTree<Key,T>::find(const Key &key)
{
    Node *x = _SearchBST(root, key);
    if(x == nullptr)
        return T();
    else {
        return x->value;
    }
}

template<typename Key, typename T>
void RBTree<Key,T>::clear()
{
    if(this->isEmpty())
        return;

    std::stack<Node *> s;
    s.push(this->root);
    while (!s.empty())
    {
        Node *temp = s.top();
        s.pop();
        if (temp->left != nil)
            s.push(temp->left);

        if (temp->right != nil)
            s.push(temp->right);
        delete temp;
        temp = nil;
    }
    root = nil;
}

template<typename Key, typename T>
void RBTree<Key, T>::writeToFile(const char * fileName)
{
    std::ofstream fout(fileName);
    fout << "digraph{\nnode [shape=record,fontname=\"Arial\",style=filled,fontcolor=white,color=green];\n" << std::endl;
    if(!this->isEmpty()){
        std::queue<Node *> q;
        q.push(this->root);
        while (!q.empty())
        {
            Node *temp = q.front();
            fout << "      " << (quintptr)temp;
            fout << "[fillcolor=" << (temp->color == Color::RED ? "red" : "black");
            fout << ",label=\"";
            fout << "{key: " << temp->key << "|val:" << temp->value << "}";
            fout << "\"];" << std::endl;
            q.pop();

            if (temp->left != nil){
                q.push(temp->left);
                fout << (quintptr)temp << "->" << (quintptr)temp->left << ";\n";
            }

            if (temp->right != nil){
                q.push(temp->right);
                fout << (quintptr)temp << "->" << (quintptr)temp->right << ";\n";
            }
        }
    }
    fout << "}";
}

template<typename Key, typename T>
void RBTree<Key,T>::accept(MyVisitor<Key, T> &v)
{
    v.visit(this);
}

template<typename Key, typename T> RBTree<Key, T>::RBTree()
{
    root = nil;
    StructureRepresentor::type = StructureRepresentor::Type::RBTree;
}

template<typename Key, typename T>
RBTree<Key, T>::~RBTree()
{
    this->clear();
}
