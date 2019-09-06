#ifndef BINARYTREE__
#define BINARYTREE__ 1

#include "nodes.hpp"

namespace lib
{
template <typename T>
class BST
{
private:
    BinNode<T> *root;
    void init() { root = nullptr; }

public:
    BST() { init(); }
    BinNode<T> *getRoot() { return root; }

    BinNode<T> *newNode(T it)
    {
        BinNode<T> *node = new BinNode<T>(it, nullptr, nullptr);
        node->left = nullptr;
        node->right = nullptr;

        return node;
    }

    BinNode<T> *insert(BinNode<T> *node, T it)
    {
        if (root == nullptr)
        {
            root = newNode(it);
            return root;
        }

        if (node == nullptr)
        {
            node = newNode(it);
            return node;
        }

        if (it < node->key)
        {
            if (node->left == nullptr)
            {
                node->setLeft(insert(node->left, it));
                return node->left;
            }
            return insert(node->left, it);
        }

        else if (it > node->key)
        {
            if (node->right == nullptr)
            {
                node->setRight(insert(node->right, it));
                return node->right;
            }
            return insert(node->right, it);
        }

        else
            return node;
    }

    BinNode<T> *insert(T it)
    {
        return insert(root, it);
    }

    void inorder(BinNode<T> *node)
    {
        if (node == nullptr)
            return;

        inorder(node->left);

        print(node->key);
        inorder(node->right);
    }

    void inorder()
    {
        inorder(root);
    }

    friend std::ostream &operator<<(std::ostream &out, BST<T> tree)
    {
        print("\n");
        print(tree.getRoot());
        print(tree.getRoot()->left);
        print(tree.getRoot()->left->right);
        print(tree.getRoot()->left->left);
        print(tree.getRoot()->right);
        return out;
    }
};
}; // namespace lib
#endif