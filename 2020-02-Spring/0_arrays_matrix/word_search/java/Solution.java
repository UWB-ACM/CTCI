class Solution {
    
    public static void main(String[] args) {
        char[][] testBoard = {{ 'A','B','C','E' }, { 'S','F','C','S' }, { 'A','D','E','E' }};
        System.out.println(exist(testBoard, "ABCCED")); // Should print true
        System.out.println(exist(testBoard,"SEE"));     // Should print true
        System.out.println(exist(testBoard, "ABCB"));   // Should print false
    }
    public static boolean exist(char[][] board, String word) {
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
        if (index == word.length()) {
            return true;
        }
        if (row < 0 || row >= board.length || col < 0 || col >= board[0].length || word.charAt(index) != board[row][col]) {
            return false;
        } else {
            board[row][col] = '*';
            boolean result = backtrack(board, index + 1, row + 1, col, word) ||
                             backtrack(board, index + 1, row, col + 1, word) ||
                             backtrack(board, index + 1, row - 1, col, word) ||
                             backtrack(board, index + 1, row, col - 1, word);
            board[row][col] = word.charAt(index);
            return result;
        }
    }
}