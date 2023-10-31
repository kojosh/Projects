#pragma once

#include "Cycle.hpp"
#include "SortedList.hpp"
#include <iostream>

template<typename T>
class DummyCycle: public Cycle<T> {
public:
    void clear() {
        std::cout << "DummyCycle::clear: doing nothing" << std::endl;
    }
    T getCurrent() const {
        std::cout << "DummyCycle::getCurrent: doing nothing" << std::endl;
        return T();
    }
    T goNext() {
        std::cout << "DummyCycle::goNext: doing nothing" << std::endl;
        return T();
    }
    T goPrevious() {
        std::cout << "DummyCycle::goPrevious: doing nothing" << std::endl;
        return T();
    }
    void insertAfter(const T &element) {
        std::cout << "DummyCycle::insertAfter: doing nothing" << std::endl;
    }
    void insertBefore(const T &element) {
        std::cout << "DummyCycle::insertBefore: doing nothing" << std::endl;
    }
    void removeCurrent() {
        std::cout << "DummyCycle::removeCurrent: doing nothing" << std::endl;
    }
    unsigned size() const {
        std::cout << "DummyCycle::size: doing nothing" << std::endl;
        return 0;
    }
};

template<typename T>
class DummySortedList: public SortedList<T> {
public:
    void clear() override {
        std::cout << "DummySortedList::clear: doing nothing" << std::endl;
    }

    T getElement(unsigned position) const override {
        std::cout << "DummySortedList::getElement: doing nothing" << std::endl;
        return T();
    }

    void insert(const T &element) override {
        std::cout << "DummySortedList::insert: doing nothing" << std::endl;
    }

    void removeElement(unsigned position) override {
        std::cout << "DummySortedList::removeElement: doing nothing" << std::endl;
    }

    void removeValue(const T &element) override {
        std::cout << "DummySortedList::removeValue: doing nothing" << std::endl;
    }

    bool searchValue(const T &element) const override {
        std::cout << "DummySortedList::searchValue: doing nothing" << std::endl;
        return false;
    }

    unsigned size() const override {
        std::cout << "DummySortedList::size: doing nothing" << std::endl;
        return 0;
    }
};
