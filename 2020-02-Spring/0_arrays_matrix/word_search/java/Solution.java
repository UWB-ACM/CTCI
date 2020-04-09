class Solution {
    private static String word;
    
    public boolean exist(char[][] board, String word) {
        this.word = word;
        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[0].length; j++) {
                if (existsHelper(board, 0, i, j)) {
                    return true;
                }
            }
        }
    }

    private boolean existsHelper(char[][] board, int index, int row, int col) {
        if (index == word.length()) {
            return true;
        }
        if (row < 0 || row >= board.length || col < 0 || col >= board[0].length || word.charAt(index) != board[row][col]) {
            return false;
        } else {
            board[row][col] = "*";
            boolean result = existsHelper(board, index + 1, row + 1, col) ||
                             existsHelper(board, index + 1, row, col + 1) ||
                             existsHelper(board, index + 1, row - 1, col) ||
                             existsHelper(board, index + 1, row, col - 1);
            board[row][col] = word.charAt(index);
            return result;
        }
    }
}