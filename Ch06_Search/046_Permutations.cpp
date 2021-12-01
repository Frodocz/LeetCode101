/**
 * 6.3 Backtracking 1
 * 46. Permutations(Medium)
 * 
 * Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.
 * 
 * Input: nums = [1,2,3], Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
 * Output: [[0,4],[1,3],[1,4],[2,2],[3,0],[3,1],[4,0]]
 * 
 * Input: nums = [0,1]
 * Output: [[0,1],[1,0]]
 * 
 * Input: nums = [1]
 * Output: [[1]]
 * 
 * 
 * Constraints:
 *  * 1 <= nums.length <= 6
 *  * -10 <= nums[i] <= 10
 *  * All the integers of nums are unique.
 * 
 */

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> ans;
    backtracking(nums, 0, ans);
    return ans;
}

void backtracking(vector<int>& nums, int level, vector<vector<int>>& ans) {
    if (level == nums.size() - 1) {
        ans.push_back(nums);
        return;
    }

    for (int i = level; i < nums.size(); ++i) {
        swap(nums[i], nums[level]); // 修改当前节点状态
        backtracking(nums, level + 1, ans); // 递归子节点
        swap(nums[i], nums[level]); // 回改当前节点状态
    }
}
