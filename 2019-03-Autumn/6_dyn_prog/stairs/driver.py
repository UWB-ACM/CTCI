import timeit
from solution import *

def run_naive_tests(l):
    return [step_combos_naive(n) for n in l]

def run_dynprog_tests(l):
    return [step_combos(n) for n in l]

def basic_test():
    l = [3, 5, 6, 17]
    print('Testing with n values: %s' % str(l))
    naive = run_naive_tests(l)
    print('Naive solution results: %s' % str(naive))
    dyn = run_dynprog_tests(l)
    print('Dynamic programming solution results: %s' % str(dyn))
    assert(naive == dyn)

def timeit_test():
    print('Running timeit tests for the solutions.')
    # l = [3, 5, 6, 17, 383, 1082]
    naive = timeit.timeit('run_naive_tests([3, 5, 6, 17])', setup='from __main__ import run_naive_tests', number=10000)
    print('Naive solution for 4 N and 10,000 repetitions: %f seconds' % naive)
    dynprog = timeit.timeit('run_dynprog_tests([3, 5, 6, 17])', setup='from __main__ import run_dynprog_tests', number=10000)
    print('Dynamic programming solution for 4 N and 10,000 repetitions: %f seconds' % dynprog)

if __name__=="__main__":
    basic_test()
    timeit_test()
