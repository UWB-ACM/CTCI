# helper function
def _check_substring(substr: str, s2: str) -> bool:
    # search s2 for desired substring
    for i in range(len(s2) - len(substr) + 1):
        if s2[i : i + len(substr)] == substr:
            return True
    return False

# a naive implementation
def longest_substring(s1: str, s2: str) -> tuple:
    indeces = (-1, -1)
    # get all possible substrings in s1
    length = len(s1)
    for i in range(length):
        for j in range(i, length):
            # for each possible substring, check for presence in s2
            substr = s1[i : j + 1]
            if _check_substring(substr, s2) and len(substr) >= indeces[1] - indeces[0]:
                indeces = (i, i + len(substr))
    return indeces

# an implementation with memoization
def longest_substring_dynamic(s1: str, s2: str, found: list) -> tuple:
    indeces = (-1, -1)
    for i in range(len(s1)):
        for j in range(len(s2)):
            # base case: beginning of string, can't check previous chars
            if i == 0 or j == 0:
                found[i][j] = 0
            # general case: check for identical neighbors in each string
            elif s1[i] == s2[j] and s1[i - 1] == s2[j - 1]:
                # increment if characters are consecutive
                found[i][j] = found[i - 1][j - 1] + 1
            # failure case: consecutive char count resets
            else:
                found[i][j] = 0
            # update indeces
            if s1[i] == s2[j] and found[i][j] + 1 >= indeces[1] - indeces[0]:
                indeces = (i - found[i][j], i + 1)
    return indeces
