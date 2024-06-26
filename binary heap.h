#ifndef binary_heap_h
#define binary_heap_h
#include "Dynamic Array.h"

template<typename U>
class BinaryHeap {
private:
    DynamicArray<U>* data;
public:
    BinaryHeap() : data(new DynamicArray<U>()) {}
    BinaryHeap(DynamicArray<U>* array) : data(array) {}

    BinaryHeap<U>* add(U value) {
        data->append(value);
        size_t index = data->getLength();
        while (value < (*data)[index / 2 + index % 2 + 1]) {
            data[index] = data[index / 2 + index % 2 + 1];
            (*data)[index / 2 + index % 2 + 1] = value;
            index = index / 2 + index % 2 + 1;
        }
        return this;
    }

    BinaryHeap<U>* organize() {
        data->sort();
        return this;
    }

    void display() {
        data->show();
    }

    U& getElement(size_t idx) {
        return data->get(idx);
    }

    size_t getSize() {
        return data->cnt();
    }

    int locate(U value) {
        for (size_t i = 0; i < data->getLength(); i++) {
            if (data->get(i) == value) {
                return i;
            }
        }
        return -1;
    }

    BinaryHeap<U> remove(size_t idx) {
        data->deLete(idx);
        return *this;
    }

    BinaryHeap<U> split(U value) {
        int idx = locate(value);
        DynamicArray<U> newArray = DynamicArray<U>(idx);
        return newArray;
    }

    BinaryHeap<U> combine(BinaryHeap<U>* heapA, BinaryHeap<U>* heapB) {
        BinaryHeap<U>* newHeap = heapA;
        for (size_t i = 0; i < heapB->data->size; i++) {
            add((*heapB)[i]);
        }
        return *newHeap;
    }

    BinaryHeap<U> transform(U(*func)(U element)) {
        data = data->map(func);
        return *this;
    }

    U aggregate(U(*func)(U elem1, U elem2), U initial) {
        return data->reduce(func, initial);
    }

    BinaryHeap<U> filter(bool(*func)(U element)) {
        return data->where(func);
    }

    U& operator[](size_t idx) {
        return (*data)[idx];
    }
};

#endif /* binary_heap_h */
