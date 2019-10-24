#include "Queue.h"
#include <iostream>

using namespace std;

int main() {
    int val;
    Queue* q = new Queue(5);
    cout << "Queue created with size 5." << endl;
    cout << "Queue size: " << q->size() << "; empty? ";
    cout << (q->isEmpty() ? "true" : "false") << endl;
    cout << endl;
    for (int i = 0; i < 6; i++) {
        cout << "Pushing " << i + 1 << " to queue. Success?: ";
        cout << (q->push(i + 1) ? "true" : "false");
        cout << " Size: " << q->size() << endl;
    }
    cout << endl;
    for (int i = 0; i < 4; i++) {
        cout << "Popping from queue. Success?: ";
        cout << (q->pop(val) ? "true" : "false");
        cout << " Size: " << q->size();
        cout  << " Val: " << val << endl;
    }
    cout << endl;
    for (int i = 0; i < 5; i++) {
        cout << "Pushing " << i + 6 << " to queue. Success?: ";
        cout << (q->push(i + 6) ? "true" : "false");
        cout << " Size: " << q->size() << endl;
    }
    cout << endl;
    for (int i = 0; i < 6; i++) {
        cout << "Popping from queue. Success?: ";
        cout << (q->pop(val) ? "true" : "false");
        cout << " Size: " << q->size();
        cout  << " Val: " << val << endl;
    }
    delete q;
    return 0;
}
