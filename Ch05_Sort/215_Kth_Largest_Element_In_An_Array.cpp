/**
 * 5.2 Quick Selection
 * 215. Kth Largest Element in an Array(Medium)
 * 
 * Given an integer array nums and an integer k, return the kth largest element in the array.
 * 
 * Note that it is the kth largest element in the sorted order, not the kth distinct element.
 * 
 * Input: nums = [3,2,1,5,6,4], k = 2, Output: 5
 * 
 * Input: nums = [3,2,3,1,2,4,5,5,6], k = 4, Output: 4
 * 
 * Input: s = "a", t = "aa", Output: ""
 * Explanation: Both 'a's from t must be included in the window.
 * Since the largest window of s only has one 'a', return empty string.
 * 
 * Constraints:
 *  * 1 <= k <= nums.length <= 10^4
 *  * -10^4 <= nums[i] <= 10^4
 * 
 */

int findKthLargest(vector<int>& nums, int k) {
    sort(nums.rbegin(), nums.rend());
    return nums[k - 1];
}

// 主函数
int findKthLargest(vector<int>& nums, int k) {
    int l = 0, r = nums.size() - 1, target = nums.size() - k; 
    while (l < r) {
        int mid = quickSelection(nums, l, r);
        if (mid == target) {
            return nums[mid];
        }
        if (mid < target) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return nums[l];
}

// 辅函数 - 快速选择
int quickSelection(vector<int>& nums, int l, int r) {
    int i = l + 1, j = r;
    while (true) {
        while (i < r && nums[i] <= nums[l]) {
            ++i;
        }
        while (l < j && nums[j] >= nums[l]) {
            --j; 
        }
        if (i >= j) {
            break;
        }
        swap(nums[i], nums[j]);
    }
    swap(nums[l], nums[j]);
    return j;
}