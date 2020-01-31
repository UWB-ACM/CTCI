from solution import *

def tests():
    s = "ADOBECODEBANC"
    t = "ABC"
    assert(minimum_window(s, t) == "BANC")
    s = "ABCDE"
    t = ""
    assert(minimum_window(s, t) == "")
    s = "IWANTAPONYFORCHRISTMAS"
    t = "NYC"
    assert(minimum_window(s, t) == "NYFORC")
    t = "PANT"
    assert(minimum_window(s, t) == "NTAP")
    t = "FLINT"
    assert(minimum_window(s, t) == "")

if __name__=='__main__':
    tests()
