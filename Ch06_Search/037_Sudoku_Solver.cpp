/**
 * 6.5 Advanced Practices 3
 * 37. Sudoku Solver(Hard)
 * 
 * Write a program to solve a Sudoku puzzle by filling the empty cells.
 * 
 * A sudoku solution must satisfy all of the following rules:
 *  * Each of the digits 1-9 must occur exactly once in each row.
 *  * Each of the digits 1-9 must occur exactly once in each column.
 *  * Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
 * 
 * The '.' character indicates empty cells.
 * 
 * 
 * Constraints:
 *  * board.length == 9
 *  * board[i].length == 9
 *  * board[i][j] is a digit or '.'.
 *  * It is guaranteed that the input board has only one solution.
 * 
 */

void solveSudoku(vector<vector<char>>& board) {
    solveSudoku(board, 0, 0);
}

bool solveSudoku(vector<vector<char>>& board, int i, int j) {
    if (i == 9) return true;
    if (j == 9) return solveSudoku(board, i + 1, 0);
    if (board[i][j] != '.') return solveSudoku(board, i, j + 1);
    
    for (char c = '1'; c <= '9'; c++) {
        if (check(board, i, j, c)) {
            board[i][j] = c;
            if(solveSudoku(board, i, j+1)) return true;
            board[i][j] = '.';
        }
    }
    return false;
}

bool check(vector<vector<char>>& board, int x, int y, int val) {
    int row = x - x % 3, col = y - y % 3;
    for (int c = 0; c < 9; c++) if (board[x][c] == val) return false; // check same row
    for (int r = 0; r < 9; r++) if (board[r][y] == val) return false; // check same col
    for (int i = row; i < row + 3; i++) {
        for (int j = col; j < col + 3; j++) {
            if (board[i][j] == val) return false;
        }
    }
    return true;
}
