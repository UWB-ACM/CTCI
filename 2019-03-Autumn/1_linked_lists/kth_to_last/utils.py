class Node:
    def __init__(self, data = None):
        self.next = None
        self.data = data

class ListUtil:
    def __init__(self, head = None):
        self.head = head

    def build_list(self, items):
        self.head = None
        tmp = self.head
        for x in items:
            if tmp is None:
                tmp = Node(x)
                self.head = tmp
            else:
                tmp.next = Node(x)
                tmp = tmp.next
    
    def print_list(self):
        tmp = self.head
        items = '[ '
        while tmp is not None:
            items += str(tmp.data)
            items += ' '
            tmp = tmp.next
        items += ']'
        return items
