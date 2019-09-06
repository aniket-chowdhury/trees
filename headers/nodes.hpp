#ifndef NODE__
#define NODE__

#include <iostream>

namespace lib
{
template <typename T>
class node
{
public:
    T element;
    node *next;
    node *prev;
    node(T elemval, node *nextval = nullptr, node *prevval = nullptr)
        : element(elemval), next(nextval), prev(prevval){};
    node(node *nextval = nullptr, node *prevval = nullptr)
        : next(nextval), prev(prevval) {}
};

template <typename K>
class BinNode
{
public:
    K key;
    BinNode *left;
    BinNode *right;

    BinNode(K keyval, BinNode *leftval = nullptr, BinNode *rightval = nullptr)
        : key(keyval), left(leftval), right(rightval) {}

    BinNode(BinNode *leftval = nullptr, BinNode *rightval = nullptr)
        : left(leftval), right(rightval) {}

    void setLeft(BinNode *bn){left = (BinNode *)bn;}
    void setRight(BinNode *bn){right = (BinNode *)bn;};

    bool isLeaf() { return (right == nullptr && left == nullptr); }

    friend std::ostream &operator<<(std::ostream &out, const BinNode* bn)
    {
        out << bn->key;
        return out;
    }
};

}; // namespace lib
#endif