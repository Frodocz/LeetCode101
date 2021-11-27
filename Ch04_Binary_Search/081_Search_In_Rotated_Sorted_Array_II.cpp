/**
 * 4.4 旋转数组查找数字
 * 81. Search in Rotated Sorted Array II(Medium)
 * 
 * There is an integer array nums sorted in non-decreasing order (not necessarily with distinct values).
 * 
 * Before being passed to your function, nums is rotated at an unknown pivot index k (0 <= k < nums.length) 
 * such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). 
 * For example, [0,1,2,4,4,4,5,6,6,7] might be rotated at pivot index 5 and become [4,5,6,6,7,0,1,2,4,4].
 * 
 * Given the array nums after the rotation and an integer target, return true if target is in nums, or false if it is not in nums.
 * You must decrease the overall operation steps as much as possible.
 * 
 * Input: nums = [2,5,6,0,0,1,2], target = 0, Output: true
 * 
 * Input: nums = [2,5,6,0,0,1,2], target = 3, Output: false
 * 
 * Constraints:
 *  * 1 <= nums.length <= 5000
 *  * -10^4 <= nums[i] <= 10^4
 *  * nums is guaranteed to be rotated at some pivot.
 *  * -10^4 <= target <= 10^4
 * 
 * Follow up: This problem is similar to Search in Rotated Sorted Array, but nums may contain duplicates. 
 * Would this affect the runtime complexity? How and why?
 */

bool search(vector<int>& nums, int target) {
    int l = 0, r = nums.size() - 1, mid;
    while (l <= r) {
        mid = l + (r - l) / 2;
        if (nums[mid] == target) return true;
        if (nums[l] == nums[mid]) { // have no idea about the array, but we can exclude nums[l] because nums[l] == nums[mid]
            ++l;
        } else if (nums[mid] <= nums[r]) { // right region is increasing
            if (target > nums[mid] && target <= nums[r]) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        } else { // left region is increasing 
            if (target < nums[mid] && target >= nums[l]) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
    }
    return false;
}
