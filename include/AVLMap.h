#pragma once
#include "IMap.h"
#include "AVLTree.h"

template <typename K, typename V>
struct MapPair {
    K key;
    V value;

    MapPair(const K& k, const V& v) : key(k), value(v) {}
    // по хорошему бы сделать компаратор но пока оствлю так

    bool operator<(const MapPair& other) const {
        return key < other.key;
    }

    bool operator>(const MapPair& other) const {
        return key > other.key;
    }

    bool operator==(const MapPair& other) const {
        return key == other.key;
    }

    friend ostream& operator<<(ostream& os, const MapPair& mp)
    {
        os << mp.key << "=" << mp.value << " ";
        return os;
    }
};

template <typename K, typename V>
class AVLMap : public IMap<K, V> {
private:
    AVLTree<MapPair<K, V>> tree;
    using NodeT = Node<MapPair<K, V>>;


public:
    AVLMap() = default;
    ~AVLMap() override = default;
    AVLMap(const AVLMap& other) : tree(other.tree) {}

    AVLMap& operator=(const AVLMap& other) {
        if (this != &other) {
            tree = other.tree;
        }
        return *this;
    }

    void print(ostream& os) const override {
        os << tree << " ";
    }


    NodeT* find(const K& key) {
        return tree.find(tree.root, MapPair<K, V>(key, V()));
    }

    V& operator[](const K& key) override {
        NodeT* node = find(key);

        if (!node) {
            tree.insert(MapPair<K, V>(key, V()));
            node = find(key);
        }

        return node->val.value;
    }

    void insert(const K& key, const V& value) override {
        NodeT* node = find(key);
        if (node) {
            node->val.value = value;
        }
        else {
            tree.insert(MapPair<K, V>(key, value));
        }
    }

    bool contains(const K& key) override {
        return find(key) != nullptr;
    }

    V* get(const K& key) override {
        NodeT* node = find(key);
        return node ? &node->val.value : nullptr;
    }


    void erase(const K& key) override {
        tree.erase(MapPair<K, V>(key, V()));
    }

    void clear() override {
        tree.destroy(tree.root);
        tree.root = nullptr;
    }
};