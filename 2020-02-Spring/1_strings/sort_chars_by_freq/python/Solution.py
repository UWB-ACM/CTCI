import collections

def frequency_sort1(word : str) -> str:
    # Edge case handling
    if not word: return word

    # Create a list of sorted characters
    # [ 'h', 'e', 'l', 'l', 'o'] --> ['e', 'h', 'l', 'l' 'o']
    word = sorted(word)
    
    # Combine identical groups of characters into strings
    # ['e', 'h', 'l', 'l', 'o'] --> ["e", "h", "ll", "o"]
    identical_groups = []
    group = [ word[0] ]

    for ch in word[1:]:
        if group[-1] != ch:
            identical_groups.append("".join(group)) # Add the group we just finished
            group = []                              # Start a new group of characters
        group.append(ch)
    identical_groups.append("".join(group))

    # Sort the groups of characters by length, from longest to shortest
    # ["e", "h", "ll", "o"] --> ["ll", "e", "h", "o"]
    identical_groups.sort(key = lambda string : len(string), reverse = True)
    
    # Combine the groups of characters into our final result
    return "".join(identical_groups)

def frequency_sort2(word : str) -> str:
    # Edge case handling
    if not word: return word

    # Create a frequency map that contains the number of times
    # each character occurs in the word
    # [ 't', 'r', 'e', 'e' ] --> { 't' : 1, 'r' : 1, 'e' : 2}
    counts = collections.Counter(word)

    # Sort the characters by the number of times they occur
    # in ascending order
    # { 't' : 1, 'r' : 1, 'e' : 2} --> { 'e' : 2, 't' : 1, 'r' : 1 }
    sorted_counts = counts.most_common()

    # Generate a list of strings with identical characters 
    # in their sorted order
    # Ex: 'e' * 2 --> 'ee'
    # { 'e' : 2, 't' : 1, 'r' : 1 } --> [ 'ee', 't', 'r' ]
    result = []
    for letter, count in sorted_counts:
        result.append(letter * count)

    # Combine the list of strings into our final result
    # ['ee', 't', 'r'] --> 'eetr'
    return "".join(result)


def main():
    print(frequency_sort1("hello"))  # Expected "eert" or "eetr"
    print(frequency_sort1("tree"))   # Expected "lleho", "llheo", "llohe", "lloeh", "lleoh", etc
    print(frequency_sort1("cccaaa")) # Expected "aaaccc" or "cccaaa"
    print(frequency_sort1("Aabb"))   # Expected "bbAa"
    print(frequency_sort1(""))       # Expected ""
    
    print(frequency_sort2("hello"))  # Expected "eert" or "eetr"
    print(frequency_sort2("tree"))   # Expected "lleho", "llheo", "llohe", "lloeh", "lleoh", etc
    print(frequency_sort2("cccaaa")) # Expected "aaaccc" or "cccaaa"
    print(frequency_sort2("Aabb"))   # Expected "bbAa"
    print(frequency_sort2(""))       # Expected ""

if __name__ == "__main__":
    main()