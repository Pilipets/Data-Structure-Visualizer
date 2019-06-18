#include "structurevisitor.h"
#include "stlmap.h"
#include "stllist.h"
#include "splaytree.h"
#include "rbtree.h"
#include<queue>

template class GetItemsVisitor<int,int>;


template<class K, class V>
GetItemsVisitor<K,V>::GetItemsVisitor() : MyVisitor<K,V>()
{

}

template<class K, class V>
void GetItemsVisitor<K,V>::visit(RBTree<K, V> *s)
{
    using Node = typename RBTree<K,V>::Node;
    const Node* data = s->data();
    amount = 0;

    if(!s->isEmpty()){
        std::queue<const Node *> q;
        q.push(data);
        while (!q.empty())
        {
            const Node *temp = q.front();
            keys.push_back(temp->key);
            values.push_back(temp->value);
            amount += 1;
            q.pop();

            if (temp->left != s->nil)
                q.push(temp->left);

            if (temp->right != s->nil)
                q.push(temp->right);
        }
    }
}

template<class K, class V>
void GetItemsVisitor<K,V>::visit(SplayTree<K,V> *s)
{
    using Node = SplayNode<K,V>;
    const Node *data = s->data();
    amount = 0;

    if(!s->isEmpty()){
        std::queue<const Node *> q;
        q.push(data);
        while (!q.empty())
        {
            const Node *temp = q.front();
            keys.push_back(temp->key);
            values.push_back(temp->value);
            amount += 1;
            q.pop();

            if (temp->left != nullptr)
                q.push(temp->left);

            if (temp->right != nullptr)
                q.push(temp->right);
        }
    }
}

template<class K, class V>
void GetItemsVisitor<K,V>::visit(StlList *s)
{
    const std::list<std::pair<K,V>> &data = s->data();
    amount = data.size();
    keys = std::vector<K>(amount);
    values = std::vector<V>(amount);

    int index = 0;
    for(const auto &item: data){
        keys[index] = item.first;
        values[index] = item.second;
        index += 1;
    }
}

template<class K, class V>
void GetItemsVisitor<K,V>::visit(StlMap *s)
{
    const std::map<K,V> &data = s->data();
    amount = data.size();
    keys = std::vector<K>(amount);
    values = std::vector<V>(amount);

    int index = 0;
    for(const auto &item: data){
        keys[index] = item.first;
        values[index] = item.second;
        index += 1;
    }
}
