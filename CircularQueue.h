#ifndef CIRCULAR_QUEUE
#define CIRCULAR_QUEUE

#include "Arduino.h"
#ifndef Arduino_h
    #include <cstdint>
    using namespace std;
#endif


template<typename T, size_t S>
class CircularQueue{
    private:
        unsigned long index;
        unsigned long length;
        T data[S];
    public:
        CircularQueue();
        unsigned long size();
        void push(T item);
        T shift();
        T peek();
};


template <typename T, size_t S>
CircularQueue<T,S>::CircularQueue(){
    this->index = S - 1;
    this->length = 0;
};

template <typename T, size_t S>
unsigned long CircularQueue<T,S>::size(){
    return this->length;
};

template <typename T, size_t S>
void CircularQueue<T,S>::push(T item){
    this->index = (this->index + 1) % S;
    data[this->index] = item;
    if(this->length < S){
        this->length += 1;
    }
};

template <typename T, size_t S>
T CircularQueue<T,S>::shift(){
    T result = data[this->index];
    if(this->length > 0){
        uint32_t startIndex = (this->index - (this->length - 1) + S) % S;
        result = data[startIndex];
        this->length -= 1;
    }
    return result; // nonsense if empty
};

template <typename T, size_t S>
T CircularQueue<T,S>::peek(){
    T result = data[this->index];
    if(this->length > 0){
        uint32_t startIndex = (this->index - (this->length - 1) + S) % S;
        result = data[startIndex];
    }
    return result;
};

#endif