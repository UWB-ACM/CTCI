#include "Queue.h"

bool Queue::pop(int& data) {
    if (!isEmpty()) {
        data = queue[front];
        front = (front + 1) % capacity;
        entries--;
        return true;
    }
    return false;
}

bool Queue::push(int data) {
    if (entries < capacity) {
        queue[(front + entries) % capacity] = data;
        entries++;
        return true;
    }
    return false;
}

bool Queue::isEmpty() {
    return entries == 0;
}

int Queue::size() {
    return entries;
}
