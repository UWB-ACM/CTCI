from utils import *
from solution import *

def main():
    assert(test_1())

def test_1():
    t1 = make_test_1()
    p = find_node(t1, 'n')
    q = find_node(t1, 't')
    lca = find_ancestor(t1, p, q)
    assert(lca.val == 'p')
    p = find_node(t1, 'f')
    q = find_node(t1, 'e')
    lca = find_ancestor(t1, p, q)
    assert(lca.val == 'f')
    p = find_node(t1, 'a')
    q = find_node(t1, 'z')
    lca = find_ancestor(t1, p, q)
    assert(lca.val == 'm')
    p = find_node(t1, 'c')
    q = find_node(t1, 'e')
    lca = find_ancestor(t1, p, q)
    assert(lca.val == 'd')
    return True

def make_test_1():
    '''
    Tree:
            m
          l   p
        d    n  x
      b   f    t z
     a c e h
    '''
    vals = ['m', 
            'l', 'p', 
            'd', None, 'n', 'x', 
            'b', 'f', None, None, 't', 'z', 
            'a', 'c', 'e', 'h', None, None, None, None, 
            None, None, None, None, None, None, None, None]
    return build_tree(vals)

if __name__=="__main__":
    main()
