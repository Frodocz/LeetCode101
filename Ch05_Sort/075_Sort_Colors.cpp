/**
 * 5.4 Advanced Practice
 * 75. Sort Colors(Medium)
 * 
 * Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, 
 * with the colors in the order red, white, and blue.
 * 
 * We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.
 * 
 * You must solve this problem without using the library's sort function.
 * 
 * 
 * Input: nums = [2,0,2,1,1,0], Output: [0,0,1,1,2,2]
 * 
 * Input: nums = [2,0,1], Output: [0,1,2]
 * 
 * Input: nums = [0], Output: [0]
 * 
 * Input: nums = [1], Output: [1]
 * 
 * Constraints:
 *  * n == nums.length
 *  * 1 <= n <= 300
 *  * nums[i] is 0, 1, or 2.
 * 
 */
void sortColors(vector<int>& nums) {
    int red = 0, blue = nums.size() - 1, i = 0;
    while (i <= blue) {
        if (nums[i] == 0 && i > red) {
            swap(nums[i], nums[red++]);
        } else if (nums[i] == 2 && i < blue) {
            swap(nums[i], nums[blue--]);
        } else {
            ++i;
        }
    }
}
