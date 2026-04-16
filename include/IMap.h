#pragma once
#include<iostream>
using namespace std;

// Интерфейс мап, т.к. делать они будут одно и то же просто посмтроены на разном
template <typename K, typename V>
class IMap {
public:
    virtual ~IMap() = default;

    virtual void insert(const K& key, const V& value) = 0;

    virtual V& operator[](const K& key) = 0;

    virtual bool contains(const K& key) = 0;

    virtual V* get(const K& key) = 0;

    virtual void erase(const K& key) = 0;

    virtual void clear() = 0;

    virtual void print(ostream& os) const = 0;

    friend ostream& operator<<(ostream& os, const IMap& im)
    {
        im.print(os);
        return os;
    }

};