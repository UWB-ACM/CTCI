def step_combos_naive(n: int):
    if n < 0:
        # we have exceeded our 
        return 0
    if n == 0:
        # we have used up all steps in this recursive path
        return 1
    return step_combos_naive(n - 1) + \
           step_combos_naive(n - 2) + \
           step_combos_naive(n - 3)

class ListWrapper(object):
    def __init__(self, n: int):
        self.combos = [0 for i in range(n)]

def step_combos(n: int):
    combos = ListWrapper(n)
    return combos_helper(n, combos)

def combos_helper(n: int, combos: ListWrapper):
    if n < 0:
        return 0
    if n == 0:
        return 1
    if combos.combos[n - 1] != 0:
        return combos.combos[n - 1]
    val = combos_helper(n - 1, combos) + \
          combos_helper(n - 2, combos) + \
          combos_helper(n - 3, combos)
    combos.combos[n - 1] = val
    return val
