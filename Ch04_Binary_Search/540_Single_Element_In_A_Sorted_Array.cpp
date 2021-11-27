/**
 * 4.5 基础练习2
 * 540. Single Element in a Sorted Array(Medium)
 * 
 * You are given a sorted array consisting of only integers where every element appears exactly twice, 
 * except for one element which appears exactly once.
 * 
 * Return the single element that appears only once.
 * 
 * Your solution must run in O(log n) time and O(1) space.
 * 
 * Input: nums = [1,1,2,3,3,4,4,8,8], Output: 2
 * Input: nums = [3,3,7,7,10,11,11], Output: 10
 * 
 * Constraints:
 *  * 1 <= nums.length <= 10^5
 *  * 0 <= nums[i] <= 10^5
 */

int singleNonDuplicate(vector<int>& nums) {
    int l = 0, r = nums.size() - 1, mid;
    while (l < r) {
        mid = l + (r - l) / 2;
        // if mid is even, then it's duplicate should be in next index.
        // or if mid is odd, then it's duplicate  should be in previous index.
        if ((mid % 2 == 0 && nums[mid] == nums[mid + 1]) || (mid % 2 == 1 && nums[mid] == nums[mid - 1])) { // The unique one is after mid
            // go to right and find the number
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    return nums[l];
}
