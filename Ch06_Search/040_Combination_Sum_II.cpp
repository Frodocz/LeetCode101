/**
 * 6.5 Advanced Practices 2
 * 40. Combination Sum II(Medium)
 * 
 * Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.
 * Each number in candidates may only be used once in the combination.
 * Note: The solution set must not contain duplicate combinations.
 * 
 * 
 * Input: candidates = [10,1,2,7,6,1,5], target = 8
 * Output: [[1,1,6],[1,2,5],[1,7],[2,6]]
 * 
 * Input: candidates = [2,5,2,1,2], target = 5
 * Output: [[1,2,2],[5]]
 * 
 * 
 * Constraints:
 *  * 1 <= candidates.length <= 100
 *  * 1 <= candidates[i] <= 50
 *  * 1 <= target <= 30
 * 
 */

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<vector<int>> ans;
    vector<int> tmp;
    sort(candidates.begin(), candidates.end()); // O(n log n)
    backtracking(candidates, target, 0, tmp, ans);
    return ans;
}

void backtracking(vector<int>& candidates, const int target, const int level, vector<int>& tmp, vector<vector<int>>& ans) {
    if (target < 0) return;
    if (target == 0) {
        ans.push_back(tmp);
        return;
    }
    for (int i = level; i < candidates.size(); i++) {
        if (i > level && candidates[i] == candidates[i-1]) continue; // check duplicate combination
        tmp.push_back(candidates[i]);
        backtracking(candidates, target - candidates[i], i + 1, tmp, ans);
        tmp.pop_back();    
    }
}
