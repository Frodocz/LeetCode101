/**
 * 6.5 Basic Practices 1
 * 130. Surrounded Regions(Medium)
 * 
 * Given an m x n matrix board containing 'X' and 'O', capture all regions that are 4-directionally surrounded by 'X'.
 * A region is captured by flipping all 'O's into 'X's in that surrounded region.
 * 
 * 
 * Input: board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]
 * Output: [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]
 * Explanation: Surrounded regions should not be on the border, which means that any 'O' on the border of the board are not flipped to 'X'. 
 * Any 'O' that is not on the border and it is not connected to an 'O' on the border will be flipped to 'X'. 
 * Two cells are connected if they are adjacent cells connected horizontally or vertically.
 * 
 * Input: board = [["X"]]
 * Output: [["X"]]
 * 
 * 
 * Constraints:
 *  * m == board.length
 *  * n == board[i].length
 *  * 1 <= m, n <= 200
 *  * board[i][j] is 'X' or 'O'.
 * 
 */

void solve(vector<vector<char>>& board) {
    int m = board.size(), n = board[0].size();
    // up & bottom border
    for (int j = 0; j < n; j++) {
        if (board[0][j] == 'O') dfs(board, 0, j, m, n);
        if (board[m - 1][j] == 'O') dfs(board, m - 1, j, m, n);
    }

    // left & right border
    for (int i = 0; i < m; i++) {
        if (board[i][0] == 'O') dfs(board, i, 0, m, n);
        if (board[i][n - 1] == 'O') dfs(board, i, n - 1, m, n);
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == 'O') {
                board[i][j] = 'X';
            }
            if (board[i][j] == '#') {
                board[i][j] = 'O';
            }
        }
    }
}

void dfs(vector<vector<char>>& board, int r, int c, int m, int n) {
    if (r >= m || r < 0 || c >= n || c < 0 || board[r][c] != 'O') return;
    board[r][c] = '#';
    dfs(board, r - 1, c, m, n);
    dfs(board, r + 1, c, m, n);
    dfs(board, r, c - 1, m, n);
    dfs(board, r, c + 1, m, n);
}
