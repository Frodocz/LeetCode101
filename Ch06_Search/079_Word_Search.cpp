/**
 * 6.3 Backtracking 3
 * 79. Word Search(Medium)
 * 
 * Given an m x n grid of characters board and a string word, return true if word exists in the grid.
 * The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. 
 * The same letter cell may not be used more than once.
 * 
 * Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
 * Output: true
 * 
 * Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
 * Output: true
 * 
 * Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
 * Output: false
 * 
 * 
 * Constraints:
 *  * m == board.length
 *  * n = board[i].length
 *  * 1 <= m, n <= 6
 *  * 1 <= word.length <= 15
 *  * board and word consists of only lowercase and uppercase English letters.
 * 
 * Follow up: Could you use search pruning to make your solution faster with a larger board?
 * 
 */

// 主函数
bool exist(vector<vector<char>>& board, string word) {
    if (board.empty()) return false;
    int m = board.size(), n = board[0].size(); vector<vector<bool>> visited(m, vector<bool>(n, false)); 
    bool find = false;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            backtracking(i, j, board, word, find, visited, 0);
        } 
    }
    return find;
}

// 辅函数
void backtracking(int i, int j, vector<vector<char>> &board, string &word, bool &find, vector<vector<bool>> &visited, int pos) {
    if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size()) return;
    if (visited[i][j] || find || board[i][j] != word[pos]) return;
    if (pos == word.size() - 1) {
        find = true;
        return; 
    }
    visited[i][j] = true; // 修改当前节点状态
    // 递归子节点
    backtracking(i + 1, j, board, word, find, visited, pos + 1); 
    backtracking(i - 1, j, board, word, find, visited, pos + 1); 
    backtracking(i, j + 1, board, word, find, visited, pos + 1); 
    backtracking(i, j - 1, board, word, find, visited, pos + 1); 
    visited[i][j] = false; // 回改当前节点状态
}