# Naive Implementation for CTCI Problem 8.11: "Coins"
def coins_naive(amount, denominations, denom_index):
    # base case: we have processed all possible larger coin denominations 
    # for this subproblem, and are only inspecting pennies now
    if denom_index >= len(denominations) - 1:
        return 1
    # create a local variable to track the number of permutations of 
    # smaller coin denominations available for this subproblem
    permutations = 0
    # now, we incrementally create subproblems for the current 
    # denomination we are looking at
    for i in range(0, (amount // denominations[denom_index]) + 1):
        # compute permutations for all subproblems and take the sum
        # NOTE: some subproblems may be identical! Hence the "naive" 
        # solution descriptor for this implementation.
        permutations += coins_naive(amount - (denominations[denom_index] * i), denominations, denom_index + 1)
    # return the permuatation count for this subproblem
    return permutations

def main():
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
    return

main()
