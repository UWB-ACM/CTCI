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

def coins_dynamic(amount, denoms, denom_index, previously_computed_values):
    # base case: we have processed all possible larger coin denominations 
    # for this subproblem, and are only inspecting pennies now
    if denom_index >= len(denoms) - 1:
        return 1
    # base case
    # If the recursive subproblem has already been solved,
    # use the existing value! 
    # NOTE: This is the core component of the dynamic implementation.
    if previously_computed_values[amount][denom_index] > 0:
        return previously_computed_values[amount][denom_index]
    # create local variable to store number of permutations for subproblem
    permutations = 0
    # now, incrementally create subproblems for the current denomination
    for i in range(0, (amount // denoms[denom_index]) + 1):
        # compute permutations for subproblems of smaller denominations
        # (Recursive call)
        permutations += coins_dynamic(amount - (denoms[denom_index] * i), denoms, denom_index + 1, previously_computed_values)
    previously_computed_values[amount][denom_index] = permutations
    return permutations

