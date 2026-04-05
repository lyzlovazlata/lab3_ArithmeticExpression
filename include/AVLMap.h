#pragma once
#include "IMap.h"
#include "AVLTree.h"

template <typename K, typename V>
struct MapPair {
    K key;
    V value;

    MapPair(const K& k, const V& v) : key(k), value(v) {}

    bool operator<(const MapPair& other) const {
        return key < other.key;
    }

    bool operator>(const MapPair& other) const {
        return key > other.key;
    }

    bool operator==(const MapPair& other) const {
        return key == other.key;
    }
};

template <typename K, typename V>
class AVLMap : public IMap<K, V> {
private:
    AVLTree<MapPair<K, V>> tree;
    using NodeT = Node<MapPair<K, V>>;

    NodeT* find(NodeT* cur, const K& key) const {
        if (!cur) return nullptr;

        if (key < cur->val.key)
            return find(cur->left, key);
        else if (key > cur->val.key)
            return find(cur->right, key);
        else
            return cur;
    }

public:
    AVLMap() = default;
    ~AVLMap() override = default;

    // вставка
    void insert(const K& key, const V& value) override {
        NodeT* node = find(tree.root, key);

        if (node) {
            node->val.value = value;
        }
        else {
            tree.insert(MapPair<K, V>(key, value));
        }
    }

    // operator[]
    V& operator[](const K& key) override {
        NodeT* node = find(tree.root, key);

        if (!node) {
            tree.insert(MapPair<K, V>(key, V()));
            node = find(tree.root, key);
        }

        return node->val.value;
    }

    // contains
    bool contains(const K& key) const override {
        return find(tree.root, key) != nullptr;
    }

    // get
    V* get(const K& key) override {
        NodeT* node = find(tree.root, key);
        if (node) return &node->val.value;
        return nullptr;
    }

    // erase
    void erase(const K& key) override {
        tree.erase(MapPair<K, V>(key, V()));
    }

    // clear
    void clear() override {
        tree.destroy(tree.root);
        tree.root = nullptr;
    }
};