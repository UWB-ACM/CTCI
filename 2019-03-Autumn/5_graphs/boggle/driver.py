from solution import *

def make_grid_1():
    return [['v', 'e', 'i', 'e'],
            ['l', 'v', 't', 'w'],
            ['r', 'e', 'n', 'x'],
            ['w', 'm', 'p', 'i']]

def make_grid_empty():
    return [[]]

def print_board(grid):
    s = '\nBoard:\n'
    for l in grid:
        for i in l:
            s += i + ' '
        s += '\n'
    print(s)

def main():
    grid = make_grid_1()
    print_board(grid)
    r1 = solve(grid, 'interview')
    assert(r1)
    print('For word \'interview\', the result is ' + str(r1))
    r2 = solve(grid, 'tent')
    assert(not r2)
    print('For word \'tent\', the result is ' + str(r2))
    grid_empty = make_grid_empty()
    print_board(grid_empty)
    r3 = solve(grid_empty, 'a')
    print('For word \'a\', the result is ' + str(r3))
    assert(not r3)

if __name__ == '__main__':
    main()
