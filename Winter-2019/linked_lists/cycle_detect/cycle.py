class Node:
    def __init__(self):
        self.data = 0
        self.next = None

    def link(self, prev, data):
        prev.next = self
        self.data = data
        return self

def hasCycle(head):
    if head is None:
        return False
    tortoise = head
    hare = head
    while hare is not None and hare.next is not None:
        tortoise = tortoise.next
        hare = hare.next.next
        if tortoise == hare:
            return True
    return False

def main():
    curr = Node()
    prev = curr
    head = curr
    for i in range(1, 10):
        curr = Node()
        prev = curr.link(prev, i)
    curr.next = head
    print("Testing list with cycle.\tResult: " + str(hasCycle(head)))
    curr.next = None
    print("Testing list without cycle.\tResult: " + str(hasCycle(head)))

main()
