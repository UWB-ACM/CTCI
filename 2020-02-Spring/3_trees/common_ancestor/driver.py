from utils import *
from solution import *

def main():
    assert(test_1())
    assert(test_2())

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

def test_2():
    t = make_test_2()
    p = t.left.left     # lower 3 node
    q = t.left.right    # 4 node
    lca = find_ancestor(t, p, q)
    assert(lca.val == 3)
    assert(lca.val == p.val)
    assert(lca != p)
    assert(lca != q)
    q = find_node(t, 10)
    lca = find_ancestor(t, p, q)
    assert(lca == t)
    assert(lca.val == 5)
    return True

def make_test_2():
    '''
    Tree:
            5
        3       9
      3   4   7   11
     1       6 8 10 12
    0 2
    '''
    vals = [5,
            3, 9,
            3, 4, 7, 11,
            1, None, None, None, 6, 8, 10, 12,
            0, 2, None, None, None, None, None, None, None, None,
            None, None, None, None]
    return build_tree(vals)

if __name__=="__main__":
    main()
