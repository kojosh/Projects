#pragma once
#include "Cycle.hpp"

template<typename T>
class DLL_Cycle: public Cycle<T> {
protected:
    struct Node {
        T value;
        Node *next;
        Node *prev;

        Node(T v = T(), Node *n = nullptr, Node *p = nullptr) :
                value(v), next(n), prev(p) {
        }
    };

    Node *head;

    // TODO add any other member variables/methods you think you'll need
    Node *current;
    unsigned SIZE;

public:
    DLL_Cycle();
    ~DLL_Cycle();

    void clear() override;
    T getCurrent() const override;
    T goNext() override;
    T goPrevious() override;
    // note that there's an `isEmpty` inherited from Cycle.hpp
    void insertAfter(const T &element) override;
    void insertBefore(const T &element) override;
    void removeCurrent() override;
    unsigned size() const override;
};

// T(n) = O(1)
template<typename T>
DLL_Cycle<T>::DLL_Cycle() :
        head(nullptr) {
    // TODO
    current = head;
    SIZE = 0;
}

// T(n) = O(1)
template<typename T>
DLL_Cycle<T>::~DLL_Cycle() {
    clear();
}

// Let n be the size of the linked list
// T(n) = O(n)
template<typename T>
void DLL_Cycle<T>::clear() {
    // TODO
    // for(int i = 0; i < this->SIZE; i++) {
    //     head = head->next;
    //     delete head;
    // }
    while(!this->isEmpty()) {
        removeCurrent();
    }
    this->SIZE = 0;
}

// T(n) = O(1) if return is considered an operation
template<typename T>
T DLL_Cycle<T>::getCurrent() const {
    // TODO
    return current->value;
}

// T(n) = O(1)
template<typename T>
T DLL_Cycle<T>::goNext() {
    // TODO
    current = current->next;
    return current->value;
}

// T(n) = O(1)
template<typename T>
T DLL_Cycle<T>::goPrevious() {
    // TODO
    current = current->prev;
    return current->value;
}

// T(n) = O(1)
template<typename T>
void DLL_Cycle<T>::insertAfter(const T &element) {
    // TODO
    if(this->SIZE == 0) {
        head = new Node(element, nullptr);
        current = head;
        current->next = current;
        current->prev = current;
    }
    else {
        Node *newNode = new Node(element, nullptr);
        Node *after = current->next;
        current->next = newNode;
        newNode->next = after;
        after->prev = newNode;
        newNode->prev = current;
    }

    this->SIZE++;
}

// T(n) = O(1)
template<typename T>
void DLL_Cycle<T>::insertBefore(const T &element) {
    // TODO
    if(this->SIZE == 0) {
        head = new Node(element);
        current = head;
        current->next = current;
        current->prev = current;
    }
    else {
        Node *newNode = new Node(element, nullptr);
        Node *before = current->prev;
        current->prev = newNode;
        newNode->prev = before;
        before->next = newNode;
        newNode->next = current;
    }
    

    this->SIZE++;
}

// T(n) = O(1)
template<typename T>
void DLL_Cycle<T>::removeCurrent() {
    // TODO
    Node *deleteThis = current;
    (current->next)->prev = current->prev;
    (current->prev)->next = current->next;
    current = current->next;
    delete deleteThis;
    this->SIZE--;
}

// T(n) = O(1)
template<typename T>
unsigned DLL_Cycle<T>::size() const {
    // TODO
    return this->SIZE;
}
