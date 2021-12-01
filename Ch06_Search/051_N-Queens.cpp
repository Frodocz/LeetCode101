/**
 * 6.3 Backtracking 4
 * 51. N-Queens(Hard)
 * 
 * The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.
 * Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.
 * Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.
 * 
 * 
 * Input: n = 4
 * Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
 * Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above
 * 
 * Input: n = 1
 * Output: [["Q"]]
 * 
 * Constraints:
 *  * 1 <= n <= 9
 * 
 */

#include <bits/stdc++.h>
using namespace std;

// 主函数
vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> ans;
    vector<string> board(n, string(n, '.'));
    vector<bool> column(n), ldiag(2 * n - 1), rdiag(2 * n - 1);
    backtracking(ans, board, column, ldiag, rdiag, 0, n);
    return ans;
}

// 辅函数
void backtracking(vector<vector<string>> &ans, vector<string> &board, vector<bool> &column, 
    vector<bool> &ldiag, vector<bool> &rdiag, int row, int n) {
    if (row == n) { 
        ans.push_back(board);
        return;
    }

    for (int i = 0; i < n; ++i) {
        if (column[i] || ldiag[n - row + i - 1] || rdiag[row + i]) continue;
        // 修改当前节点状态
        board[row][i] = 'Q';
        column[i] = ldiag[n - row + i - 1] = rdiag[row + i] = true;
        // 递归子节点
        backtracking(ans, board, column, ldiag, rdiag, row + 1, n);
        // 回改当前节点状态
        board[row][i] = '.';
        column[i] = ldiag[n-row+i-1] = rdiag[row+i] = false;
    }
}
