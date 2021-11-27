/**
 * 4.2 求开方
 * 69. Sqrt(x)(Easy)
 * 
 * Given a non-negative integer x, compute and return the square root of x.
 * Since the return type is an integer, the decimal digits are truncated, and only the integer part of the result is returned.
 * 
 * Note: You are not allowed to use any built-in exponent function or operator, such as pow(x, 0.5) or x ** 0.5.
 * 
 * Input: x = 4, Output: 2
 * 
 * Input: x = 8, Output: 2
 * Explanation: The square root of 8 is 2.82842..., and since the decimal part is truncated, 2 is returned.
 * 
 * Constraints:
 *  * 0 <= x <= 2^31 - 1
 */

// Newton's Method
int mySqrt(int x) {
    long long ans = x;
    while (ans * ans > x) {
        ans = (ans + x / ans) / 2;
    }
    return ans;
}

// Binary Search
int mySqrt(int a) {
    if (a == 0) return a;
    int l = 1, r = a, mid, sqrt;
    while (l <= r) {
        mid = l + (r - l) / 2; sqrt = a / mid;
        if (sqrt == mid) {
            return mid;
        } else if (mid > sqrt) {
            r = mid - 1; 
        } else {
            l = mid + 1; 
        }
    }
    return r; 
}