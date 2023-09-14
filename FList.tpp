#include "FList.h"

template<typename T>
FList<T>::FList()
        :m_head(nullptr)
{
}

template<typename T>
FList<T>::FList(const FList<T> &oth)
        :m_head(nullptr)
{
    for (const T &value: oth)
        insert(size(), value);

}

template<typename T>
FList<T>::FList(FList<T> &&oth) noexcept
        :m_head(oth.m_head)
{
    oth.m_head = nullptr;
}

template<typename T>
FList<T>& FList<T>::operator=(const FList<T> &oth) {
    if(this != &oth) {
        clear();
        for (const T& value : oth) {
            insert(size(), value);
        }
    }
    return *this;
}

template<typename T>
FList<T>& FList<T>::operator=(FList<T> &&oth)  noexcept {
    if(this != &oth) {
        clear();
        m_head = oth.m_head;
        oth.m_head = nullptr;
    }
    return *this;
}

template<typename T>
FList<T>::FList(std::initializer_list<T> values)
        :m_head(nullptr)
{
    for(const T& value : values) {
        push_back(value);
    }
}

template<typename T>
FList<T>::~FList() {
    clear();
}

template<typename T>
void FList<T>::insert(int i, const T &item) {
    assert(i >= 0 && i <= size());
    if(i == 0) {
        auto tmp = new Node<T>(item, m_head);
        m_head = tmp;
    } else {
        auto curr = m_head;
        for(int j = 0; j < i - 1; ++j) {
            curr = curr->next;
        }
        auto newNode = new Node<T>(item,curr->next);
        curr->next = newNode;
    }
}

template<typename T>
void FList<T>::push_back(const T &item) {
    if(m_head == nullptr) {
        m_head = new Node<T>(item);
    } else {
        Node<T>* curr = m_head;
        while(curr->next != nullptr) {
            curr = curr->next;
        }
        curr->next = new Node<T>(item);
    }
}

template<typename T>
void FList<T>::erase(int i) {
    assert(i >= 0 && i < size());

    if(i == 0) {
        auto tmp = m_head;
        m_head = m_head->next;
        delete tmp;
    } else {
        auto curr = m_head;
        for(int j = 0; j < i - 1; ++j) {
            curr = curr->next;
        }
        auto tmp = curr->next;
        curr->next = tmp->next;
        delete tmp;
    }
}

template<typename T>
int FList<T>::find(const T &item) const {
    auto curr = m_head;
    int index = 0;

    while(curr->next != nullptr) {
        if(curr->data == item) {
            return index;
        }
        ++index;
        curr = curr->next;
    }
    return -1;
}

template<typename T>
bool FList<T>::empty() const {
    return m_head == nullptr;
}

template<typename T>
void FList<T>::clear() noexcept{
    while(!empty()) {
        erase(0);
    }
}

template<typename T>
T FList<T>::get_value(int i) const {
    assert(i >= 0 && i < size());
    auto curr = m_head;
    int index = 0;

    while(curr->next != nullptr) {
        if(index == i) {
            return curr->data;
        }
        ++index;
        curr= curr->next;
    }
    return T();
}

template<typename T>
int FList<T>::size() const {
    auto tmp = m_head;
    int size = 0;
    while(tmp != nullptr) {
        ++size;
        tmp = tmp->next;
    }
    return size;
}

template<typename T>
void FList<T>::reverse() {
    if(m_head == nullptr){
        return;
    }

    Node<T>* prev = nullptr;
    Node<T>* curr = m_head;
    Node<T>* next = nullptr;
    while(curr != nullptr) {
        next = curr->next;
        curr->next = prev;

        prev = curr;
        curr = next;
    }
    m_head = prev;
}

template<typename T>
void FList<T>::merge(FList<T> &list1, FList<T> &list2) {
    clear();
    int m_size = size();
    auto curr1 = list1.m_head;
    auto curr2 = list2.m_head;
    while (curr1 != nullptr && curr2 != nullptr) {
        if(curr1->data <= curr2->data) {
            insert(m_size, curr1->data);
            curr1 = curr1->next;
        } else {
            insert(m_size,curr2->data);
            curr2 = curr2->next;
        }
    }
    while (curr1 != nullptr) {
        insert(m_size, curr1->data);
        curr1 = curr1->next;
    }
    while (curr2 != nullptr) {
        insert(m_size, curr2->data);
        curr2 = curr2->next;
    }
}

template<typename T>
T& FList<T>::front() {
    assert(m_head != nullptr);
    return m_head->data;
}

template<typename T>
void FList<T>::print() {
    if(empty()) {
        std::cout << "List is empty! " << std::endl;
    }

    auto tmp = m_head;
    while(tmp != nullptr) {
        std::cout << tmp->data << " ";
        tmp=tmp->next;
    }
    std::cout << std::endl;
}

template<typename T>
bool FList<T>::operator==(const FList<T> &oth) const {
    if(this->size() != oth.size()) {
        return false;
    }

    auto it1 = this->begin();
    auto it2 = oth.begin();

    while(it1 != end()) {
        if(*it1 != *it2) {
            return false;
        }
        ++it1;
        ++it2;
    }
    return true;
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const FList<T>& list){
    if(list.empty()) {
        os << "List is empty! ";
    } else {
        Node<T>* tmp = list.m_head;
        while(tmp != nullptr) {
            os << tmp->data << " ";
            tmp = tmp->next;
        }
    }
    return os;
}

template<typename T>
T& FList<T>::Iterator::operator*() {
    return ptr->data;
}

template<typename T>
T* FList<T>::Iterator::operator->() {
    return &(ptr->val);
}

template<typename T>
FList<T>::Iterator::Iterator(Node<T>* node)
        :ptr(node) {}

template<typename T>
typename FList<T>::Iterator &FList<T>::Iterator::operator++() {
    ptr = ptr->next;
    return *this;
}

template<typename T>
bool FList<T>::Iterator::operator==(const FList::Iterator &oth) {
    return ptr == oth.ptr;
}

template<typename T>
bool FList<T>::Iterator::operator!=(const FList::Iterator &oth) {
    return this->ptr != oth.ptr;
}

template<typename T>
typename FList<T>::Iterator FList<T>::begin() {
    return Iterator(m_head);
}

template<typename T>
typename FList<T>::Iterator FList<T>::end() {
    return Iterator(nullptr);
}
