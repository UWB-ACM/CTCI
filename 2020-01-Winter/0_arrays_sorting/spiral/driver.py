from solution import *

def print_matrix(mtx):
    print('[')
    for row in mtx:
        print('    ', str(row))
    print(']')

def main(): 
    print('Test 4x4 alphabet:')
    t1 = [['a', 'b', 'c', 'd'], ['e', 'f', 'g', 'h'], 
          ['i', 'j', 'k', 'l'], ['m', 'n', 'o', 'p']]
    print_matrix(t1)
    print('Result: ', str(spiral_order(t1)))
    print('\nTest 5x7 ints:')
    t2 = [[1, 2, 3, 4, 5], [6, 7, 8, 9, 10],
          [11, 12, 13, 14, 15], [16, 17, 18, 19, 20],
          [21, 22, 23, 24, 25], [26, 27, 28, 29, 30],
          [31, 32, 33, 34, 35]]
    print_matrix(t2)
    print('Result: ', str(spiral_order(t2)))
    print('\nTest 3x0 (empty) matrix:')
    t3 = [[], [], []]
    print_matrix(t3)
    print('Result: ', str(spiral_order(t3)))

if __name__=='__main__':
    main()
