def solve(grid, word):
    if not grid or not word:
        return False
    for row in range(len(grid)):
        for col in range(len(grid[row])):
            if dfs(grid, word, 0, row, col, set()):
                return True
    return False

def dfs(grid, word, word_idx, row, col, visited):
    # handle edge cases:
    # 1. check to ensure we have not processed entire word
    # 2. check to ensure our indices are still in bounds
    # 3. check to make sure we haven't visited this node
    if word_idx >= len(word): return True
    if row < 0 or row >= len(grid): return False
    if col < 0 or col >= len(grid[0]): return False
    if (row, col) in visited: return False
    # we are still traversing graph; now, check for letter alignment
    if grid[row][col] != word[word_idx]:
        # letters are mismatched; terminate this search
        return False
    # keep searching; search in all 8 directions from current node
    visited.add((row, col))
    return dfs(grid, word, word_idx + 1, row + 1, col, visited) or  \
            dfs(grid, word, word_idx + 1, row + 1, col + 1, visited) or \
            dfs(grid, word, word_idx + 1, row + 1, col - 1, visited) or \
            dfs(grid, word, word_idx + 1, row, col + 1, visited) or \
            dfs(grid, word, word_idx + 1, row, col - 1, visited) or \
            dfs(grid, word, word_idx + 1, row - 1, col + 1, visited) or \
            dfs(grid, word, word_idx + 1, row - 1, col - 1, visited) or \
            dfs(grid, word, word_idx + 1, row - 1, col, visited)
