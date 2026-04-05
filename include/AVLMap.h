#pragma once
#include "AVLTree.h"
template <typename K, typename V>
struct MapPair {
    K key;
    V value;

    MapPair() = default;
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
class AVLMap {
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

    // вставка
    void insert(const K& key, const V& value) {
        NodeT* node = find(tree.root, key);

        if (node) {
            // если ключ уже есть — обновляем значение
            node->val.value = value;
        }
        else {
            tree.insert(MapPair<K, V>(key, value));
        }
    }

    // доступ как в std::map
    V& operator[](const K& key) {
        NodeT* node = find(tree.root, key);

        if (!node) {
            tree.insert(MapPair<K, V>(key, V()));
            node = find(tree.root, key);
        }

        return node->val.value;
    }

    // поиск
    bool contains(const K& key) const {
        return find(tree.root, key) != nullptr;
    }

    // получение (с проверкой)
    V* get(const K& key) {
        NodeT* node = find(tree.root, key);
        if (node) return &node->val.value;
        return nullptr;
    }

    // удаление
    void erase(const K& key) {
        tree.erase(MapPair<K, V>(key, V()));
    }
};