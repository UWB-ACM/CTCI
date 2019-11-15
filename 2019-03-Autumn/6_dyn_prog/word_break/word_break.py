def word_break(s: str, wordDict: list) -> bool:
    wordDict = set(wordDict)
    lengths = sorted(set(len(word) for word in wordDict))
    dp = set()
    dp.add(0)
    for i in range(1, len(s) + 1):
        for length in lengths:
            if i - length in dp and s[i - length: i] in wordDict:
                dp.add(i)
                break
    return len(s) in dp

if __name__ == "__main__":
    tests = [
        (["leetcode", ["leet", "code"]], True),
        (["applepenapple", ["apple", "pen"]], True),
        (["catsandog", ["cats", "dog", "sand", "and", "cat"]], False),
        (["aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab",
        ["a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"]],
        False),
    ]

    for i, (input, output) in enumerate(tests):
        assert(word_break(*input) == output)
        print("Test", i, "Input:", *input)
        print("Result:", word_break(*input))