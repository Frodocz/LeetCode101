/**
 * 4.5 进阶练习1
 * Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
 * 
 * The overall run time complexity should be O(log (m+n)).
 * 
 * Input: nums1 = [1,3], nums2 = [2], Output: 2.00000
 * Explanation: merged array = [1,2,3] and median is 2.
 * 
 * Input: nums1 = [1,2], nums2 = [3,4], Output: 2.50000
 * Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
 * 
 * Input: nums1 = [0,0], nums2 = [0,0], Output: 0.00000
 * 
 * Input: nums1 = [], nums2 = [1], Output: 1.00000
 * 
 * Input: nums1 = [2], nums2 = [], Output: 2.00000
 * 
 * Constraints:
 *  * nums1.length == m
 *  * nums2.length == n
 *  * 0 <= m <= 1000
 *  * 0 <= n <= 1000
 *  * 1 <= m + n <= 2000
 *  * -10^6 <= nums1[i], nums2[i] <= 10^6
 */

double findMedianSortedArrays(vector<int>& A, vector<int>& B) {
    int m = A.size(), n = B.size();
    if (m > n) return findMedianSortedArrays(B, A);
    int l = 0, r = m, halfLen = (m + n + 1) / 2;
    int lMax, rMin;
    int i, j;
    while (l <= r) {
        i = l + (r - l) / 2;
        j = halfLen - i;
        if (i < m && A[i] < B[j - 1]) {
            // i is too small, increase it, no need to check j > 0 (make B[j-1] valid) because
            // i < m --> j > 0
            // proof: m <= n, i < m ==> j = (m+n+1)/2 - i > (m+n+1)/2 - m >= (2*m+1)/2 - m >= 0
            l = i + 1;
        } else if (i > 0 && A[i - 1] > B[j]) {
            // i is too big, decrease it, no need to check j < n (make B[j] valid) because
            // i > 0 --> j < n
            // proof: m <= n, i > 0 ==> j = (m+n+1)/2 - i < (m+n+1)/2 <= (2*n+1)/2 <= n
            r = i - 1;
        } else {
            // i is perfect
            if (i == 0) lMax = B[j - 1];
            else if (j == 0) lMax = A[i - 1];
            else lMax = max(A[i - 1], B[j - 1]);

            if ((m + n) % 2 == 1)
                return lMax;

            if (i == m) rMin = B[j];
            else if (j == n) rMin = A[i];
            else rMin = min(A[i], B[j]);

            return (lMax + rMin) / 2.0;
        }
    }
    return -1;
}
