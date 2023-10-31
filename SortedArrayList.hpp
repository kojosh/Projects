#pragma once
#include "SortedList.hpp"

#define MAX_SIZE 100

template <typename T>
class SortedArrayList : public SortedList<T> {
private:
    T *list;
    unsigned length;
    int maxSize;
public:
    SortedArrayList(int = MAX_SIZE);
    ~SortedArrayList();
    void clear() override;
    T getElement(unsigned) const override;
    void insert(const T &) override;
    bool isEmpty() const override;
    void removeElement(unsigned) override;
    void removeValue(const T &) override;
    bool searchValue(const T &) const override;
    unsigned size() const override;
};

// T(n) = O(1)
template <typename T>
SortedArrayList<T>::SortedArrayList(int maxSize) {
    this->maxSize = maxSize;
    list = new T[maxSize];
    this->length = 0;
}

// T(n) = O(1)
template <typename T>
SortedArrayList<T>::~SortedArrayList() {
    clear();
}

// T(n) = O(1)
template <typename T>
void SortedArrayList<T>::clear() {
    delete [] list;
    list = new T[maxSize];
    this->length = 0;
}

// T(n) = O(1)
template<typename T>
T SortedArrayList<T>::getElement(unsigned position) const {
    return list[position];
}

// T(n) = O(n)
template<typename T>
void SortedArrayList<T>::insert(const T &element) {
    if(this->length > maxSize) {
        std::cout << "insert error: max size reached" << std::endl;
    }
	else {
        int count = 0;
		while((element > list[count]) && (count < this->length)) {
            count++;
        }
        for(int i = this->length; i > count; i--) {
            list[i] = list[i-1];
        }
		list[count] = element;
        this->length++;
	}
}

// T(n) = O(1)
template<typename T>
bool SortedArrayList<T>::isEmpty() const {
    if(this->length == 0) {
        return true;
    }
    else return false;
}

// T(n) = O(n)
template<typename T>
void SortedArrayList<T>::removeElement(unsigned position) {
    if(position < 0 || position > maxSize) {
		std::cout << "remove error: position out of bounds" << std::endl;
	}
	else {
		for(int i = position; i < this->length; i++) {
            list[i] = list[i+1];
        }
        this->length--;
	}
}

// T(n) = O(n)
template<typename T>
void SortedArrayList<T>::removeValue(const T &element) {
    if(searchValue(element)) {
        int idx;
        // Shift all elements down one index
        for(int i = 0; i < this->length; i++) {
            if(list[i] == element) {
                idx = i;
            }
        }
        for(int i = idx; i < this->length; i++) {
            list[i] = list[i+1];
        }
        this->length--;
    }
    else {
        std::cout << "removeValue error: element not found in library" << std::endl;
    }
}

// T(n) = O(n)
template<typename T>
bool SortedArrayList<T>::searchValue(const T &element) const {
    int position = -1, 
        idx = 0,
        first = 0,
        last = (this->length) - 1,
        middle;

    bool found = false;

    // Binary search algorithm
    while(!found && first <= last) {
        middle = (first+last)/2;
        if(list[middle] == element) {
            found = true;
            position = middle;
        }
        else if(list[middle] > element) {
            last = middle-1;
        }
        else
            first = middle+1;
    }
    return found;
}

// T(n) = O(1)
template<typename T>
unsigned SortedArrayList<T>::size() const {
    return this->length;
}
