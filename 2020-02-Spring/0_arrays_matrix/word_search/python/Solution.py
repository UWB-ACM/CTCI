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
    if (len(word) == 0):
        return True
    if row < 0 or row == len(board) or col < 0 or col == len(board[0]):
        return False
    if board[row][col] != word[0]:
        return False
    
    result = False
    board[row][col] = '*'
    for row_delta, col_delta in [(0, 1), (1, 0), (0, -1), (-1, 0)]:
        result = backtrack(row + row_delta, col + col_delta, word[1:], board)
        if result: break
    
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