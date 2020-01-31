def freq(x):
    return { c: x.count(c) for c in x }

def is_dict_subset(stable, new):
    """
    Determine if one dictionary is a subset of another dictionary.
    
    For this to be true, all keys in 'stable' must be present in 'new' 
    and the frequency count of all elements in 'stable' must be included 
    in 'new'.
    """
    for k in stable:
        if k not in new or new[k] < stable[k]:
            return False
    return True

def minimum_window(s, t):
    if not s or not t: return ""
    # s is a long string that we must search for minimum window
    # t is a string containing all characters to be searched
    left = right = 0    # indeces
    window = ""
    frequency_table = freq(t)
    while right < len(s):
        curr = freq(s[left:right + 1])
        if is_dict_subset(frequency_table, curr):
            if not window or right - left < len(window):
                window = s[left:right + 1]
            left += 1
        else:
            right += 1
    return window
