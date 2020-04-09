class Solution {
    public static void main(String[] args) {
        char[][] testBoard = {{ 'A','B','C','E' }, { 'S','F','C','S' }, { 'A','D','E','E' }};
        System.out.println(exist(testBoard, "ABCCED")); // Should print true
        System.out.println(exist(testBoard,"SEE"));     // Should print true
        System.out.println(exist(testBoard, "ABCB"));   // Should print false
    }

    public static boolean exist(char[][] board, String word) {
        // For every single cell in the board, we want to try searching for the word.
        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[0].length; j++) {
                if (backtrack(board, 0, i, j, word)) {
                    return true;
                }
            }
        }
        return false;
    }

    private static boolean backtrack(char[][] board, int index, int row, int col, String word) {
        // Check the base case (Have we found the word that we're looking for?)
        if (index == word.length()) {
            return true;
        }

        // Check if the boundaries of the board have been exceeded
        if (row < 0 || row >= board.length || col < 0 || col >= board[0].length) {
            return false;
        // Check if we have encountered a character that should not be at this position in the word
        } else if (word.charAt(index) != board[row][col])) {
            return false;
        } else {
            // Mark this cell as visited
            board[row][col] = '*';
            // Recursively explore neighboring cells for the rest of the word
            boolean result = backtrack(board, index + 1, row + 1, col, word) ||
                             backtrack(board, index + 1, row, col + 1, word) ||
                             backtrack(board, index + 1, row - 1, col, word) ||
                             backtrack(board, index + 1, row, col - 1, word);
            // Revert this cell back to its original state after backtracking
            // We do this so other explorations of the board can use this cell again
            board[row][col] = word.charAt(index);
            return result;
        }
    }
}