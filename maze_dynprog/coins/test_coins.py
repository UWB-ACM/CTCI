import timeit
import numpy as np
from coins import *

def run_tests():
    # initialize denominations array
    denoms = [25, 10, 5, 1]
    print("Testing naive solution:")
    # for 5 cents, we expect the result to be 2
    print("Input: 5\tExpected: 2\tActual: " + str(coins_naive(5, denoms, 0)) + "\tCorrect? %s" % str(coins_naive(5, denoms, 0) == 2))
    # for 10 cents, we expect the result to be 4
    print("Input: 10\tExpected: 4\tActual: " + str(coins_naive(10, denoms, 0)) + "\tCorrect? %s" % str(coins_naive(10, denoms, 0) == 4))
    '''
        For 25 cents, we expect 13 combinations:
        | P  | N  | D  | Q  |
        |----|----|----|----|
        | 25 | 0  | 0  | 0  |
        | 20 | 1  | 0  | 0  |
        | 15 | 2  | 0  | 0  |
        | 10 | 3  | 0  | 0  |
        | 5  | 4  | 0  | 0  |
        | 0  | 5  | 0  | 0  |
        | 15 | 0  | 1  | 0  |
        | 10 | 1  | 1  | 0  |
        | 5  | 2  | 1  | 0  |
        | 0  | 3  | 1  | 0  |
        | 5  | 0  | 2  | 0  |
        | 0  | 1  | 2  | 0  |
        | 0  | 0  | 0  | 1  |
    '''
    print("Input: 25\tExpected: 13\tActual: " + str(coins_naive(25, denoms, 0)) + "\tCorrect? %s" % str(coins_naive(25, denoms, 0) == 13))
    print("Input: 500\tExpected: 19006\tActual: " + str(coins_naive(500, denoms, 0)) + "\tCorrect? %s" % str(coins_naive(500, denoms, 0) == 19006))
    # now, let's test the dynamic solution
    print("Testing dynamic solution:")
    answers = {5: 2, 10: 4, 25: 13, 500: 19006}
    for i in [5, 10, 25, 500]:
        temp_map = np.zeros((i + 1, len(denoms)))
        result = coins_dynamic(i, denoms, 0, temp_map)
        print("Input: " + str(i) + "\tExpected: " + str(answers[i]) + "\tActual: " + str(result) + "\tCorrect? %s" % str(result == answers[i]))
    return

def run_timeit():
    setup = ''
    naive = '''
def coins_naive(amount, denominations, denom_index):
    if denom_index >= len(denominations) - 1:
        return 1
    permutations = 0
    for i in range(0, (amount // denominations[denom_index]) + 1):
        permutations += coins_naive(amount - (denominations[denom_index] * i), denominations, denom_index + 1)
    return permutations

denoms = [25, 10, 5, 1]
coins_naive(500, denoms, 0)
'''
    # run timeit for naive solution
    print("Testing timeit for naive solution (N = 500, repetitions = 1000)")
    print(str(timeit.timeit(setup = '', stmt = naive, number=1000)))
    print("Testing timeit for dynamic solution solution (N = 500, repetitions = 1000)")
    dynamic = '''
def coins_dynamic(amount, denoms, denom_index, previously_computed_values):
    if denom_index >= len(denoms) - 1:
        return 1
    if previously_computed_values[amount][denom_index] > 0:
        return previously_computed_values[amount][denom_index]
    permutations = 0
    for i in range(0, (amount // denoms[denom_index]) + 1):
        permutations += coins_dynamic(amount - (denoms[denom_index] * i), denoms, denom_index + 1, previously_computed_values)
    previously_computed_values[amount][denom_index] = permutations
    return permutations

denoms = [25, 10, 5, 1]
temp_map = np.zeros((501, 4))
coins_dynamic(500, denoms, 0, temp_map)
'''
    print(str(timeit.timeit(setup = 'import numpy as np', stmt = dynamic, number=1000)))
    return

def main():
    run_tests()
    run_timeit()

main()
