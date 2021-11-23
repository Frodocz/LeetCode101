/**
 * 2.4 进阶练习2
 * 665. Non-decreasing Array(Easy)
 * 
 * Given an array nums with n integers, your task is to check if it could become non-decreasing by modifying at most one element.
 * We define an array is non-decreasing if nums[i] <= nums[i + 1] holds for every i (0-based) such that (0 <= i <= n - 2).
 * 
 * Input: nums = [4,2,3], Output: true
 * Explanation: You could modify the first 4 to 1 to get a non-decreasing array.
 * 
 * Input: nums = [4,2,1], Output: false
 * Explanation: You can't get a non-decreasing array by modify at most one element.
 * 
 * Constraints:
 *  * n == nums.length
 *  * 1 <= n <= 10^4
 *  * -10^5 <= nums[i] <= 10^5
 */

#include <bits/stdc++.h>
using namespace std;

bool checkPossibility(vector<int>& nums) {
    int modified = 0;
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] < nums[i - 1]) {
            if (modified++) return false;
            (i - 2 < 0 || nums[i - 2] <= nums[i]) ? nums[i - 1] = nums[i] : nums[i] = nums[i - 1];
        }
    }
    return true;
}
