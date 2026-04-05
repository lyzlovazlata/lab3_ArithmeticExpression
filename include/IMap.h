#pragma once

template <typename K, typename V>
class IMap {
public:
    virtual ~IMap() = default;

    // вставка или обновление
    virtual void insert(const K& key, const V& value) = 0;

    // доступ как map[key]
    virtual V& operator[](const K& key) = 0;

    // поиск
    virtual bool contains(const K& key) const = 0;

    // безопасное получение
    virtual V* get(const K& key) = 0;

    // удаление
    virtual void erase(const K& key) = 0;

    // очистка
    virtual void clear() = 0;
};