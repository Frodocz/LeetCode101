/**
 * 3.6 基础练习1
 * 633. Sum of Square Numbers(Medium)
 * 
 * Given a non-negative integer c, decide whether there're two integers a and b such that a^2 + b^2 = c.
 * 
 * The testcases will be generated such that the answer is unique.
 * A substring is a contiguous sequence of characters within the string.
 * 
 * Input: c = 5, Output: true
 * Input: c = 3, Output: false
 * Input: c = 4, Output: true
 * Input: c = 2, Output: true
 * Input: c = 1, Output: true
 * 
 * Constraints:
 *  * 0 <= c <= 2^31 - 1
 */

bool judgeSquareSum(int c) {
    if (c < 0) return false;
    long long sum = 0;
    long long l = 0, r = sqrt(c) + 1;
    while (l <= r) {
        sum = l * l + r * r;
        if (sum == c) return true;
        else if (sum < c) ++l;
        else --r;
    }
    return false;
}