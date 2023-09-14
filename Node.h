#ifndef FORWARDLIST_NODE_H
#define FORWARDLIST_NODE_H

template<typename T>
struct Node{
    explicit Node(const T& val, Node<T>* n = nullptr)
            :data(val), next(n) {}

    T data;
    Node<T>* next;
};

#endif //FORWARDLIST_NODE_H
