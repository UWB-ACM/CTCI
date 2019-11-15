def step_combos_naive(n: int):
    if n < 0:
        # we have exceeded the number of steps in the staircase
        return 0
    if n == 0:
        # we have completed a unique stair pattern
        return 1
    return step_combos_naive(n - 1) + \
           step_combos_naive(n - 2) + \
           step_combos_naive(n - 3)

def step_combos(n: int):
    combos = [0 for i in range(n)]
    return combos_helper(n, combos)

def combos_helper(n: int, combos: list):
    if n < 0:
        return 0
    if n == 0:
        return 1
    if combos[n - 1] == 0:
        val = combos_helper(n - 1, combos) + \
              combos_helper(n - 2, combos) + \
              combos_helper(n - 3, combos)
        combos[n - 1] = val
    return combos[n - 1]
