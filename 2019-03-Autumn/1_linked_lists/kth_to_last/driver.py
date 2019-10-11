from solutions import *

def test_solution(fn):
    # Expect a standard response
    t1 = ListUtil()
    t1.build_list(['a', 'b', 'c', 'd', 'e', 'f'])
    print('List: ', t1.print_list(), '\tLooking for k = 3')
    assert(fn(3, t1.head).data == 'd')
    print('Result: ', fn(3, t1.head).data)
    # Expect None
    t1.build_list([1, 2, 3, 'a', 'b', 'c'])
    print('List: ', t1.print_list(), '\tLooking for k = 7')
    assert(fn(7, t1.head) is None)
    print('Result: ', fn(7, t1.head))

if __name__=="__main__":
    print('Iterative tests:')
    test_solution(get_kth_to_last_iterative)
    print('\nRecursive tests:')
    test_solution(get_kth_to_last_recursive)
