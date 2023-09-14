#ifndef FORWARDLIST_FLIST_H
#define FORWARDLIST_FLIST_H
#include <iostream>
#include <cassert>
#include <initializer_list>
#include "Node.h"

template<typename T>
class FList  {
private:
    Node<T>* m_head;
public:
    FList();
    FList(const FList<T>&);
    FList(FList<T>&&) noexcept;
    FList<T>& operator=(const FList<T>&);
    FList<T>& operator=(FList<T>&&) noexcept;
    FList(std::initializer_list<T>);
    ~FList();

    void insert(int, const T&);
    void push_back(const T&);
    void erase(int);

    [[maybe_unused]] [[nodiscard]] int find(const T&) const;
    [[nodiscard]] bool empty() const;
    void clear() noexcept;
    [[nodiscard]] T get_value(int) const;
    [[nodiscard]] int size() const;
    void reverse();
    void merge(FList<T>&, FList<T>&);

    T& front();
    void print();

    bool operator==(const FList<T>&) const;

    template<typename U>
    friend std::ostream& operator<<(std::ostream& os, const FList<U>& list);
public:
    class Iterator{
    private:
        Node<T>* ptr;
    public:
        explicit Iterator(Node<T>*);

        T& operator*();
        T* operator->();
        Iterator& operator++();
        bool operator==(const Iterator&);
        bool operator!=(const Iterator&);
    };

public:
    Iterator begin();
    Iterator end();

};

//template class FList<int>;
#include "FList.tpp"

#endif //FORWARDLIST_FLIST_H
