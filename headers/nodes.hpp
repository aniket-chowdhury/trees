#ifndef NODE__
#define NODE__

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
        : element(elemval), next(nextval), prev(prevval);
    node(node *nextval = nullptr, node *prevval = nullptr)
        : next(nextval), prev(prevval) {}
};

template <typename T, typename K>
class BinNode
{
public:
    K key;
    T element;
    BinNode *left;
    BinNode *right;

    BinNode(K keyval, T elemval, BinNode *leftval = nullptr, BinNode *rightval = nullptr)
        : key(keyval), element(elemval), left(leftval), right(rightval) {}

    BinNode(BinNode *leftval = nullptr, BinNode *rightval = nullptr)
        : left(leftval), right(rightval) {}

    void setLeft(BinNode *bn){left = (BinNode *)bn};
    void setRight(BinNode *bn){right = (BinNode *)bn};

    bool isLeaf() { return (right == nullptr && left == nullptr); }

    friend ostream &operator<<(ostream &out, const BinNode &bn)
    {
        out << bn;
        return bn;
    }
};

}; // namespace lib
#endif