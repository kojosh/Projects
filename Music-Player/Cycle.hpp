#pragma once

#include <iostream>

template <typename T>
class Cycle {
public:
    virtual ~Cycle() {}

    // Removes everything from the cycle, resetting it to the initial state
    virtual void clear() = 0;

    // Returns whatever the current element is
    virtual T getCurrent() const = 0;

    // Moves the current element to the next element in the cycle.
    // Returns whatever the new current element is.
    virtual T goNext() = 0;

    // Moves the current element to the previous element in the cycle.
    // Returns whatever the new current element is.
    virtual T goPrevious() = 0;

    // Adds another element into the cycle.
    // Assuming the cycle is non-empty, the new element should go after the current one.
    virtual void insertAfter(const T& element) = 0;

    // Adds another element into the cycle.
    // Assuming the cycle is non-empty, the new element should go before the current one.
    virtual void insertBefore(const T& element) = 0;

    // Returns true if and only if the cycle is empty.
    // (This one is already implemented for you.)
    virtual bool isEmpty() const;

    // Removes the current element from the cycle.
    // If the cycle is then non-empty, the new current element should be whatever came next
    virtual void removeCurrent() = 0;

    // Returns how many elements are in the cycle.
    virtual unsigned size() const = 0;

    // overloaded stream insertion operator to make printing easier
    template<typename U>
    friend std::ostream& operator<<(std::ostream&, Cycle<U>&);
};

template <typename T>
bool Cycle<T>::isEmpty() const {
    return size() == 0;
}

template <typename T>
std::ostream& operator<<(std::ostream &outStream, Cycle<T> &myObj) {
    if (myObj.isEmpty()) {
        outStream << "Cycle is empty, no elements to display.";
    } else {
        for (unsigned i = 0; i < myObj.size() - 1; i++) {
            outStream << myObj.getCurrent() << ", ";
            myObj.goNext();
        }
        outStream << myObj.getCurrent() << "...";
        myObj.goNext(); // make sure we leave the cycle where it started
    }

    return outStream;
}
