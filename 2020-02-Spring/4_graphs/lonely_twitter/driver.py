from solution import *

def test_1():
    t = {
        'Bob': set(['Sandy', 'Theo', 'Frank', 'Rachel']),
        'Sandy': set(['Theo', 'Sally']),
        'Frank': set(['Sandy', 'Sally', 'Rachel', 'Theo']),
        'Theo': set(['Bob', 'Sally']),
        'Sally': set([]),
        'Rachel': set(['Sally']),
    }
    print_data(t)
    res = lonely(t)
    print('The loneliest user is', res, '\n')
    assert(res == 'Frank')
    return True

def test_2():
    t = {
        'Mindy': set(['Mork']),
        'Mork': set(['Mindy']),
        'Orson': set(['Mork', 'Mindy'])
    }
    print_data(t)
    res = lonely(t)
    print('The loneliest user is', res, '\n')
    assert(res == 'Orson')
    return True

def test_3():
    t = {
        'Peter': set(['Lois', 'Chris', 'Brian']),
        'Lois': set(['Chris', 'Brian', 'Stewie']),
        'Brian': set(['Stewie', 'Lois']),
        'Meg': set(['Peter', 'Lois', 'Chris', 'Brian', 'Stewie']),
        'Chris': set(['Peter', 'Lois', 'Brian']),
        'Stewie': set([])
    }
    print_data(t)
    res = lonely(t)
    print('The loneliest user is', res, '\n')
    assert(res == 'Meg')
    return True

def print_data(t):
    print('User graph:\n{')
    for k, v in t.items():
        print('\t', k, ': ', v)
    print('}')

def main():
    assert(test_1())
    assert(test_2())
    assert(test_3())

if __name__=='__main__':
    main()
