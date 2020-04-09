def exist(board, word):
    """
    :type board: List[List[str]]
    :type word:  str
    :rtype: bool
    """
    rows = len(board)
    cols = len(board[0])
    for row in range(rows):
        for col in range(cols):
            if backtrack(row, col, word, board):
                return True
    return False

def backtrack(row, col, word, board):
    # Check if the word has been found
    if (len(word) == 0):
        return True
    # Check if the boundaries of the board have been reached
    if row < 0 or row == len(board) or col < 0 or col == len(board[0]):
        return False
    # Check if we have found a character that shouldn't be at this position in the word
    if board[row][col] != word[0]:
        return False
    
    result = False
    # Mark current cell as visited
    board[row][col] = '*'
    # Check neighboring cells for the rest of the word
    for row_delta, col_delta in [(0, 1), (1, 0), (0, -1), (-1, 0)]:
        result = backtrack(row + row_delta, col + col_delta, word[1:], board)
        if result: break
    # Reset changes to this cell so other explorations of the board can use it
    board[row][col] = word[0]
    return result

def main():
    test_board = [['A','B','C','E'],
                  ['S','F','C','S'],
                  ['A','D','E','E' ]]
    print(exist(test_board, "ABCCED"))
    print(exist(test_board, "SEE"))
    print(exist(test_board, "ABCB"))

if __name__ == "__main__":
    main()