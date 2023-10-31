#pragma once

#include <iostream>

template <typename T>
class SortedList {
public:
    virtual ~SortedList() {}

    // Removes everything from the list, resetting it to the initial state
    virtual void clear() = 0;

    // Returns the element at the specified position
    // (The first element is at position 0; the last element is at position size()-1)
    virtual T getElement(unsigned position) const = 0;

    // Insert an element into the list, finding the position that keeps the list sorted
    virtual void insert(const T &element) = 0;

    // Returns true if and only if the list is empty.
    // (This one is already implemented for you.)
    virtual bool isEmpty() const;

    // Remove an element from the list at the specified position
    // (The first element is at position 0; the last element is at position size()-1)
    virtual void removeElement(unsigned position) = 0;

    // Remove an element from the list, specified by its value, if the list contains it
    virtual void removeValue(const T &element) = 0;

    // Search the list for an element with the specified value
    virtual bool searchValue(const T &element) const = 0;

    // Returns the number of elements in the list
    virtual unsigned size() const = 0;

    // overloaded stream insertion operator to make printing easier
    template<typename U>
    friend std::ostream& operator<<(std::ostream&, const SortedList<U>&);
};

template <typename T>
bool SortedList<T>::isEmpty() const {
    return size() == 0;
}

template <typename T>
std::ostream& operator<<(std::ostream &outStream, const SortedList<T> &myObj) {
    if (myObj.isEmpty()) {
        outStream << "SortedList is empty, no elements to display.";
    } else {
        for (unsigned i = 0; i < myObj.size() - 1; i++) {
            outStream << myObj.getElement(i) << ", ";
        }
        outStream << myObj.getElement(myObj.size() - 1);
    }

    return outStream;
}
