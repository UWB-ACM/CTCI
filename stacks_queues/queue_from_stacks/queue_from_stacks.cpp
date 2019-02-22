#include <string>
#include <stack>
#include <cassert>
#include <iostream>

using namespace std;

template<class T>
class TwoStackQueue {

    // public methods
    public:

        // constructor
        TwoStackQueue() {
            front = new stack<T>();
            back = new stack<T>();
        }

        // destructor
        ~TwoStackQueue() {
            delete front;
            delete back;
        }

        // push item into the queue
        void Push(T item) {
            back->push(item);
            if (front->size() == 0) {
                this->rebalance();
            }
        }

        // pop item from the queue
        bool Pop() {
            if (front->size() != 0) {
                // useful to see the item that is being popped
                // return val also indicates whether operation was successful
                cout << "popping item: " << front->top() << endl;
                front->pop();
                if (front->size() == 0) {
                    this->rebalance();
                }
                return true;
            }
            return false;
        }

        // get the queue's size
        int size() {
            return front->size() + back->size();
        }
                
    private:
        // data members
        stack<T>* front;
        stack<T>* back;

        // function to move queue items when front->stack is empty
        void rebalance() {
            while (back->size() > 0) {
                front->push(back->top());
                back->pop();
            }
        }
};

int main() {
    TwoStackQueue<string> strQueue;
    assert(strQueue.size() == 0);
    strQueue.Push("hello");
    strQueue.Push("world");
    assert(strQueue.size() == 2);
    bool success = strQueue.Pop();
    assert(success);
    strQueue.Push("on");
    strQueue.Push("fire");
    strQueue.Push("abc");
    strQueue.Push("xyz");
    assert(strQueue.size() == 5);
    success = strQueue.Pop();
    assert(success);
    success = strQueue.Pop();
    assert(success);
    success = strQueue.Pop();
    assert(success);
    success = strQueue.Pop();
    assert(success);
    success = strQueue.Pop();
    assert(success);
    success = strQueue.Pop();
    assert(!success);
    return 0;
}
