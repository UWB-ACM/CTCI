from utils import *

def recurse_kth(k: int, current: Node, head: Node):
    # Base case: we have reached end of list.
    # Return the value we expect to report for the previous node, 
    # along with a boolean flag about whether our search should continue.
    if current is None:
        return True, 1
    proceed, depth = recurse_kth(k, current.next, head)
    # We have terminated; pass the reported values up the stack.
    if not proceed:
        return False, depth
    # We have found our target node.
    if depth == k:
        return False, current
    # We need to continue looking for our target node.
    elif depth < k and current is not head:
        return True, depth + 1
    # If no previous conditions are met, we will not be able to find a match.
    return False, None

def get_kth_to_last_recursive(k: int, head: Node = None):
    # edge case
    if head is None:
        return None
    # enter recursive function, return desired value
    return recurse_kth(k, head, head)[1]

def get_kth_to_last_iterative(k: int, head: Node = None):
    if head is None:
        return None
    leader = head
    target = head
    # Move our leader pointer forward k - 1 nodes.
    for x in range(k - 1):
        # Edge case: our list is shorter than k nodes.
        if leader.next is None:
            return None
        else:
            leader = leader.next
    # Move leader and target pointers forward in lockstep until 
    # the end of the list is reached.
    while leader.next is not None:
        leader = leader.next
        target = target.next
    return target
