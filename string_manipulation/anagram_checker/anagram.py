# function definition
def is_anagram(str1, str2):
    # Simple solution:
    # Construct a dictionary for each string, with the letter
    # as key and frequency as value.
    # Compare the resulting dictionaries for equality.
    
    # String 1
    d1 = {}
    # iterate over string (O(N) complexity)
    for letter in str1:
        if letter in d1:
            # if the key already exists, increment the existing count
            d1[letter] += 1
        else:
            # If it doesn't exist, add it to the dictionary 
            d1[letter] = 1
    
    # String 2
    d2 = {}
    for letter in str2:
        if letter in d2:
            d2[letter] += 1
        else:
            d2[letter] = 1
    
    # Final dictionary comparison
    return d1 == d2

# Tests
print("abcd -> bcda: " + str(is_anagram("abcd", "bcda"))) # True
print("mary -> ryan: " + str(is_anagram("mary", "ryan"))) # False
print("asdfjkl; -> ;lkjdsdfad: " + str(is_anagram("asdfjkl;", ";lkjdsdfad"))) # False
print("aaaaadaa -> daaaaaaa: " + str(is_anagram("aaaaadaa", "daaaaaaa"))) # True
