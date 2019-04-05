'''

The class definition for a Queue implemented with two stacks.

Here, lists are utilized as the data structure to represent the Stack.

In accordance with the nature of a stack, the list methods append() 
and pop() will be used exclusively.

'''
class TwoStackQueue:

    # the object's constructor
    def __init__(self):
        self.front = []
        self.back = []

    # public-facing method to add item to queue
    def push(self, item):
        self.back.append(item)
        if len(self.front) < 1:
            self._rebalance()
        return

    # public-facing method to pop item from queue
    def pop(self):
        # check for empty stacks first
        if self.size() == 0:
            print('Nothing to pop')
            return None
        else:
            item = self.front.pop()
            if len(self.front) < 1:
                self._rebalance()
            return item

    # public-facing helper method to get queue's size
    def size(self):
        return len(self.front) + len(self.back)

    # internal method to ensure the queue remains balanced
    # NOTE: this is the core logic of how to manage the two stacks
    # in this particular implementation.
    def _rebalance(self):
        # print("BEFORE REBAL: back: " + str(self.back) + " ... front: " + str(self.front))
        # This implementation only calls _rebalance() when the "front" 
        # stack is empty.
        while len(self.back) > 0:
            self.front.append(self.back.pop())
        # print("AFTER REBAL: back: " + str(self.back) + " ... front: " + str(self.front))
        return
    

# a driver function to test the class
def main():
    queue = TwoStackQueue()
    import pdb; pdb.set_trace()
    # expect a none-type object returned when popping from an empty queue
    print('pop: ' + str(queue.pop()))
    print('push 5')
    queue.push(5)
    print('push 6')
    queue.push(6)
    print('push 7')
    queue.push(7)
    print('push 8')
    queue.push(8)
    print('push 9')
    queue.push(9)
    print('push "a"')
    queue.push('a')
    print('size: ' + str(queue.size()))
    print('pop: ' + str(queue.pop()))
    print('push "4"')
    queue.push('4')
    print('pop: ' + str(queue.pop()))
    print('pop: ' + str(queue.pop()))
    print('pop: ' + str(queue.pop()))
    print('pop: ' + str(queue.pop()))
    print('pop: ' + str(queue.pop()))
    print('pop: ' + str(queue.pop()))
    print('size: ' + str(queue.size()))
    print('pop: ' + str(queue.pop()))
    return

main()
