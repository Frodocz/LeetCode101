/**
 * 4.3 查找区间
 * 34. Find First and Last Position of Element in Sorted Array Medium)
 * 
 * Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.
 * 
 * If target is not found in the array, return [-1, -1].
 * 
 * You must write an algorithm with O(log n) runtime complexity.
 * 
 * Input: nums = [5,7,7,8,8,10], target = 8, Output: [3,4]
 * 
 * Input: nums = [5,7,7,8,8,10], target = 6, Output: [-1,-1]
 * 
 * Input: nums = [], target = 0, Output: [-1,-1]
 * 
 * Constraints:
 *  * 0 <= nums.length <= 10^5
 *  * -10^9 <= nums[i] <= 10^9
 *  * nums is a non-decreasing array.
 *  * -10^9 <= target <= 10^9
 */

// May also try std::equal_range()
vector<int> searchRange(vector<int>& nums, int target) {
    // implement lower_bound and upper_bound
    if (nums.empty()) return vector<int>{-1, -1};
    int lo = lower_bound(nums, target);
    int hi = upper_bound(nums, target) - 1;
    if (lo == nums.size() || nums[lo] != target) {
        return vector<int>{-1, -1};
    }
    return vector<int>{lo, hi};
}

int lower_bound(vector<int>& nums, int target) {
    int l = 0, r = nums.size(), mid;
    while (l < r) {
        mid = l + (r - l) / 2;
        if (nums[mid] < target) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    return l;
}

int upper_bound(vector<int> &nums, int target) {
    int l = 0, r = nums.size(), mid;
    while (l < r) {
        mid = l + (r - l) / 2;
        if (nums[mid] <= target) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    return l;
}
