#pragma once
#include <vector>
#include <functional>
#include <iostream>
#include "IMap.h"
#include "tset.h"
using namespace std;

template <class K, class V>
struct Pair {
    K key;
    V value;
public:
    Pair() : key(K()), value(V()) {}
    Pair(K _key, V _value) : key(_key), value(_value) {};
};

template<class K, class V>
class HTable : public IMap<K, V> {
    std::vector<Pair<K, V>> data;
    TSet _using;
    TSet _deleted;
    int size;

    // не путать - эта штука получает из условной строки инт, первая хешка
    int hash(const K& key) const {
        std::hash<K> hasher;
        size_t h = hasher(key);
        return static_cast<int>((h * 7 + 3) % static_cast<size_t>(size));
    }

    // а вот эта уже получает из инта еще один хеш и так далее
    int rehash(int p) const {
        return (p * 7 + 3) % size;
    }

    int find(const K& key) const {
        int p = hash(key);

        for (int i = 0; i < size; i++) {
            if (_using.IsMember(p)) {
                if (data[p].key == key)
                    return p;
            }
            else if (!_deleted.IsMember(p)) {
                // ячейки не было никогда!!! можно не искать еще возможные хеши
                return -1;
            }
            // если есть возможность что это значение просто лежит дальше - ищем хеши еще
            p = rehash(p);
        }
        return -1;
    }

    void resize() {
        HTable new_table(size * 2);
        for (int i = 0; i < size; i++) {
            if (_using.IsMember(i))
                new_table.insert(data[i].key, data[i].value);
        }
        // прост опоменяем указатели свапами
        std::swap(data, new_table.data);
        std::swap(_using, new_table._using);
        std::swap(_deleted, new_table._deleted);
        std::swap(size, new_table.size);
    }

public:

    HTable(int _size = 100) : _using(_size), _deleted(_size), data(_size), size(_size) {}

    HTable(const HTable& other)
        : data(other.data), _using(other._using), _deleted(other._deleted), size(other.size) {
    }

    HTable& operator=(const HTable& other) {
        if (this == &other)
            return *this;
        data = other.data;
        _using = other._using;
        _deleted = other._deleted;
        size = other.size;
        return *this;
    }

    ~HTable() override = default;

    void insert(const K& key, const V& value) override {
        int pos = find(key);
        if (pos != -1) {
            data[pos].value = value;
            return;
        }

        int p = hash(key);

        for (int i = 0; i < size; i++) {
            if (!_using.IsMember(p)) {
                // если ячейка не занята, то она либо совсем нетронутая либо удалялась, но нам все равно, мы просто делаем одно и то же
                data[p] = Pair<K, V>(key, value);
                _using.InsElem(p);
                _deleted.DelElem(p);
                return;
            }
            // занята - ищем есть ли еще место для нее?
            p = rehash(p);
        }


        resize();// нет свободного места, значит увеличиваем и вставляем
        insert(key, value);
    }

    // доступ по индексу, если нужно создаем ячейку как и в авл мапе
    V& operator[](const K& key) override {
        int pos = find(key);
        if (pos == -1) {
            insert(key, V());
            pos = find(key);
        }
        return data[pos].value;
    }

    // Проверка наличия ключа
    bool contains(const K& key) override {
        return find(key) != -1;
    }

    V* get(const K& key) override {
        int pos = find(key);
        if (pos != -1)
            return &data[pos].value;
        return nullptr;
    }

    // удаление можно делать разными способами - можно было с пересобиранием (жуть), можно с перехешированием хвоста, но я сделала "ленивое"
    // neerc.ifmo.ru спасибо
    void erase(const K& key) override {
        int pos = find(key);
        if (pos != -1) {
            _using.DelElem(pos);
            _deleted.InsElem(pos);
        }
    }

    void clear() override {
        _using = TSet(size);
        _deleted = TSet(size);
        for (int i = 0; i < size; ++i) data[i] = Pair<K, V>();
    }

    void print(ostream& os) const override {
        for (int i = 0; i < size; i++) {
            if (_using.IsMember(i))
                os << data[i].key << " = " << data[i].value << endl;
        }
    }
};