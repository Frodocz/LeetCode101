/**
 * 6.3 Backtracking 2
 * 46. Combinations(Medium)
 * 
 * Given two integers n and k, return all possible combinations of k numbers out of the range [1, n].
 * You may return the answer in any order.
 * 
 * Input: n = 4, k = 2
 * Output:[[2,4],[3,4],[2,3],[1,2],[1,3],[1,4]]
 * 
 * Input: n = 1, k = 1
 * Output: [[1]]
 * 
 * 
 * Constraints:
 *  * 1 <= n <= 20
 *  * 1 <= k <= n
 * 
 */

vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> ans;
    vector<int> comb(k);
    int count = 0;
    backtracking(ans, comb, count, 1, n, k);
    return ans;
}

void backtracking(vector<vector<int>>& ans, vector<int>& comb, int& count, int pos, int n, int k) {
    if (count == k) {
        ans.push_back(comb);
        return;
    }

    for (int i = pos; i <= n; ++i) {
        comb[count++] = i; // 修改当前节点状态
        backtracking(ans, comb, count, i + 1, n, k);
        --count; // 回改当前节点状态
    }
}