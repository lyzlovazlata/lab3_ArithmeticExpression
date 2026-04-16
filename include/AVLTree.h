#pragma once
#include <algorithm>
#include <iostream>
#include "TStack.h"

using namespace std;

template <typename T>
struct Node {
    Node* left;
    Node* right;
    T val;
    int height;

    Node() : left(nullptr), right(nullptr), val(), height(0) {}
    Node(const T& _val) : left(nullptr), right(nullptr), val(_val), height(0) {}

    friend ostream& operator<<(ostream& os, const Node& n) {
        os << n.val;
        return os;
    }
};

template <typename T>
class AVLTree {

    int getHeight(Node<T>* cur) const {
        if (cur) return cur->height;
        else return -1;
    }

    void updHeight(Node<T>* cur) {
        if (!cur) return;
        cur->height = 1 + std::max(getHeight(cur->left), getHeight(cur->right));
    }

    int getDiff(Node<T>* cur) const {
        return getHeight(cur->right) - getHeight(cur->left);
    }

    // райтрайт малое лев
    Node<T>* SLRotate(Node<T>* cur) {
        if (!cur || getDiff(cur) < 2 || getDiff(cur->right) < 0) return cur;

        Node<T>* b = cur->right;
        Node<T>* p2 = b->left;

        b->left = cur;
        cur->right = p2;

        updHeight(cur);
        updHeight(b);

        return b;
    }

    // лефт лефт малое прав
    Node<T>* SRRotate(Node<T>* cur) {
        if (!cur || getDiff(cur) > -2 || getDiff(cur->left) > 0) return cur;

        Node<T>* b = cur->left;
        Node<T>* p2 = b->right;

        b->right = cur;
        cur->left = p2;

        updHeight(cur);
        updHeight(b);

        return b;
    }

    // райт лефт большое лев
    Node<T>* BLRotate(Node<T>* cur) {
        if (!cur || getDiff(cur) < 2 || getDiff(cur->right) >= 0) return cur;

        cur->right = SRRotate(cur->right);
        return SLRotate(cur);
    }

    //лефт райт большое прав
    Node<T>* BRRotate(Node<T>* cur) {
        if (!cur || getDiff(cur) > -2 || getDiff(cur->left) < 0) return cur;

        cur->left = SLRotate(cur->left);
        return SRRotate(cur);
    }
    Node<T>* rebalance(Node<T>* cur) {
        if (!cur) return cur;

        updHeight(cur);
        int b = getDiff(cur);

        if (b >= 2) {
            if (getDiff(cur->right) < 0)
                return BLRotate(cur);
            else
                return SLRotate(cur);
        }

        if (b <= -2) {
            if (getDiff(cur->left) > 0)
                return BRRotate(cur);
            else
                return SRRotate(cur);
        }

        return cur;
    }

    // теперь итеративнеый подход - действую через дв стека
    Node<T>* copyTree(Node<T>* otherRoot) {
        if (!otherRoot) return nullptr;

        const size_t STACK_SIZE = 1000; // такой же как макс стак дай бог хватит 
        TStack<Node<T>*> otkuda(STACK_SIZE);
        TStack<Node<T>*> kuda(STACK_SIZE);

        Node<T>* newRoot = new Node<T>(otherRoot->val);
        newRoot->height = otherRoot->height;

        otkuda.push(otherRoot);
        kuda.push(newRoot);

        while (!otkuda.isEmpty()) {
            Node<T>* otk = otkuda.pop();
            Node<T>* kud = kuda.pop();

            // смотрим левого
            if (otk->left) {
                kud->left = new Node<T>(otk->left->val);
                kud->left->height = otk->left->height;
                // соответственно как только опбработали родителя надо уходить глубже, а из-за стеков мы рассмотрим вообще все
                otkuda.push(otk->left);
                kuda.push(kud->left);
            }

            if (otk->right) {
                kud->right = new Node<T>(otk->right->val);
                kud->right->height = otk->right->height;
                otkuda.push(otk->right);
                kuda.push(kud->right);
            }
        }
        return newRoot;
    }

    // удаляю левое, потом ПРАВОЕ (не топ, потому что не доберемся до детей)
    void destroyTree(Node<T>* root) {
        if (!root) return;

        const size_t STACK_SIZE = 1000;

        TStack<Node<T>*> st(STACK_SIZE);
        Node<T>* cur = root;
        Node<T>* lastnode = nullptr; // нужн чтобы проверять правое поддерево

        while (!st.isEmpty()||cur) {
            if (cur) {
                st.push(cur);
                cur = cur->left;
            }
            else {
                Node<T>* n = st.top();
                // обяхательно смотрим обработан ли правый потомок, потому что иначе потеряем его!!!!!
                if (n->right && lastnode != n->right) {
                    cur = n->right;
                }
                else {
                    lastnode = n;
                    st.pop();
                    delete lastnode;
                }
            }
        }
    }

    Node<T>* findNode(Node<T>* cur, const T& val) const {
        while (cur) {
            if (val < cur->val) cur = cur->left;
            else if (val > cur->val) cur = cur->right;
            else return cur;
        }
        return nullptr;
    }

    void LRTgoSTREAM(ostream& os) const {
        if (!root) return;

        const size_t STACK_SIZE = 1000;
        TStack<Node<T>*> st(STACK_SIZE);
        Node<T>* cur = root;
        Node<T>* lastnode = nullptr;

        while (!st.isEmpty() || cur) {
            if (cur) {
                st.push(cur);
                cur = cur->left;
            }
            else {
                Node<T>* n = st.top();
                if (n->right && lastnode != n->right) {
                    cur = n->right;
                }
                else {
                    lastnode = st.pop();
                    os << lastnode->val << " ";
                }
            }
        }
    }

public:
    Node<T>* root;

    AVLTree() : root(nullptr) {}

    AVLTree(const AVLTree& other) {
        root = copyTree(other.root);
    }

    AVLTree& operator=(const AVLTree& other) {
        if (this != &other) {
            destroyTree(root);
            root = copyTree(other.root);
        }
        return *this;
    }

    ~AVLTree() {
        destroyTree(root);
    }

    void insert(const T& val) {
        if (!root) {
            root = new Node<T>(val);
            return;
        }

        const size_t STACK_SIZE = 1000;
        TStack<Node<T>*> path(STACK_SIZE);

        Node<T>* cur = root;
        while (cur) {
            path.push(cur);
            if (val < cur->val) {
                if (!cur->left) {
                    cur->left = new Node<T>(val);
                    break;
                }
                cur = cur->left;
            }
            else if (val > cur->val) {
                if (!cur->right) {
                    cur->right = new Node<T>(val);
                    break;
                }
                cur = cur->right;
            }
            else return;//уже есть
        }

        // вставили теперь балансим (нарушение может быть только у ПРЕДКОВ, поэтому чекаем путь)
        while (!path.isEmpty()) {
            Node<T>* node = path.pop();
            Node<T>* balanced = rebalance(node);

            if (!path.isEmpty()) {
                Node<T>* parent = path.top();
                //определяем какой был потомок и куда прицепить уже ЗАБАЛАНШЕНУЮ часть
                if (parent->left == node)
                    parent->left = balanced;
                else
                    parent->right = balanced;
            }
            else root = balanced;
        }
    }

    void erase(const T& val) {
        if (!root) return;

        const size_t STACK_SIZE = 1000;
        TStack<Node<T>*> path(STACK_SIZE);

        Node<T>* cur = root;
        while (cur) {
            path.push(cur);
            if (val < cur->val) {
                cur = cur->left;
            }
            else if (val > cur->val) {
                cur = cur->right;
            }
            else {
                break;
            }
        }

        if (!cur) {
            path.clear();
            return;
        }

        if (cur->left && cur->right) {
            Node<T>* minParent = cur;
            Node<T>* minNode = cur->right;

            path.push(minNode);

            while (minNode->left) {
                minParent = minNode;
                minNode = minNode->left;
                path.push(minNode);
            }

            cur->val = minNode->val;
            if (!path.isEmpty() && path.top() == minNode) {
                path.pop(); // присвоили - убрали из стека чтоб по удаленному не идти
            }

            Node<T>* child = minNode->right;
            if (minParent->left == minNode) minParent->left = child;
            else minParent->right = child;
            delete minNode;
        }
        else {
            Node<T>* child;
            if (cur->left) child = cur->left;
            else child = cur->right;

            path.pop();

            if (!path.isEmpty()) {
                Node<T>* parent = path.top();
                if (parent->left == cur) parent->left = child;
                else parent->right = child;
            }
            else root = child;
            delete cur;
        }

        // ребалансим как в инсерте
        while (!path.isEmpty()) {
            Node<T>* node = path.pop();
            Node<T>* balanced = rebalance(node);

            if (!path.isEmpty()) {
                Node<T>* parent = path.top();
                if (parent->left == node)
                    parent->left = balanced;
                else
                    parent->right = balanced;
            }
            else {
                root = balanced;
            }
        }
    }

    Node<T>* find(const T& val) const {
        return findNode(root, val);
    }

    friend ostream& operator<<(ostream& os, const AVLTree& tree) {
        tree.LRTgoSTREAM(os);
        return os;
    
    }

    void clear() {
        destroyTree(root);
        root = nullptr;
    }
};