from solution import *
from timeit import timeit

def dyn_soltn_list(s1: str, s2: str):
    return [ [-1 for x in range(len(s2) + 1)] for y in range(len(s1) + 1) ]

def main():
    # our "found" variable will store the substring size for previous searches
    tests =   { "s1": "s2",
                "": "123",
                "BADBADNOTGOODFlightoftheConchordsRivalConsolesFourTetAesopRock": "RivalConsolesAesopRockFlightoftheConchordsBADBADNOTGOOD",
                "hi this is a sentence": "you might not like it but this is a hrng;lsdkfja;lkejs;ldj",
                "123": "312",
                "1s": "193587s",
                "uwbothellacmhostscrackingthecodinginterview": "codingwithuwbothellacm",
                "abcdefg1": "hijklmnopqrstuv1"
              }
    for s1, s2 in tests.items():
        substr = None
        print('S1: ' + s1)
        print('S2: ' + s2)
        result = longest_substring(s1, s2)
        if result != (-1, -1):
            substr = s1[result[0]:result[1]]
        print('Naive solution:\t\tIndeces: ' + str(result) + '\tSubstring: \'' + str(substr) + '\'')
        
        substr = None
        result = longest_substring_dynamic(s1, s2, dyn_soltn_list(s1, s2))
        if result != (-1, -1):
            substr = s1[result[0]:result[1]]
        print('Dynprog solution:\tIndeces: ' + str(result) + '\tSubstring: \'' + str(substr) + '\'\n')

main()
