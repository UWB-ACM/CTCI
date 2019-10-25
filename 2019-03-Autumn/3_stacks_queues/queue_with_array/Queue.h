#ifndef QUEUE_H__
#define QUEUE_H__

// non-template Queue class for queueing integers
class Queue {
private:
    int* queue = nullptr;
    int front = 0;
    int entries = 0;
    int capacity = 0;
public:
    Queue(int capacity) {
        queue = new int[capacity];
        this->capacity = capacity;
    }
    ~Queue() {
        delete[] queue;
    }
    bool push(int val);
    bool pop(int& data);
    bool isEmpty();
    int size();
};

#endif      // QUEUE_H__
