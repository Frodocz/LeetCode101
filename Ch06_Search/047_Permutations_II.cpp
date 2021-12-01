/**
 * 6.5 Advanced Practices 1
 * 47. Permutations II(Medium)
 * 
 * Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order.
 * 
 * Input: nums = [1,1,2]
 * Output: [[1,1,2], [1,2,1], [2,1,1]]
 * 
 * Input: nums = [1,2,3]
 * Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
 * 
 * 
 * Constraints:
 *  * 1 <= nums.length <= 8
 *  * -10 <= nums[i] <= 10
 * 
 */

vector<vector<int>> permuteUnique(vector<int>& nums) {
    vector<vector<int>> ans;
    backtracking(nums, 0, ans);
    return ans;
}

void backtracking(vector<int>& nums, int level, vector<vector<int>>& ans) {
    if (level == nums.size()) { 
        ans.push_back(nums); 
        return; 
    }
    unordered_set<int> st;
    for (int j = level; j < nums.size(); ++j) {
        if (st.count(nums[j]) == 1) { 
            continue; 
        }
        st.insert(nums[j]);
        swap(nums[level], nums[j]);
        backtracking(nums, level + 1, ans);
        swap(nums[level], nums[j]);
    }    
}