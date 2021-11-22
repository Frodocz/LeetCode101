/**
 * 2.3 区间问题1
 * 135. Candy(Hard)
 * 
 * Given an array of intervals intervals where intervals[i] = [start_i, end_i], 
 * return the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.
 * 
 * Input: intervals = [[1,2],[2,3],[3,4],[1,3]], Output: 1
 * Explanation: [1,3] can be removed and the rest of the intervals are non-overlapping.
 * 
 * Input: intervals = [[1,2],[1,2],[1,2]], Output: 2
 * Explanation: You need to remove two [1,2] to make the rest of the intervals non-overlapping.
 * 
 * Input: intervals = [[1,2],[2,3]], Output: 0
 * Explanation: You don't need to remove any of the intervals since they're already non-overlapping.
 * 
 * Constraints:
 *  * 1 <= intervals.length <= 105
 *  * intervals[i].length == 2
 *  * -5 * 10^4 <= starti < endi <= 5 * 10^4
 */

#include <bits/stdc++.h>
using namespace std;

int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    if (intervals.empty()) return 0;
    int n = intervals.size();
    sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b) {
        return a[1] < b[1];
    });

    int removed = 0, prev = intervals[0][1];
    for (int i = 1; i < n; ++i) {
        if (intervals[i][0] < prev) { // find an overlap
            ++removed;
        } else {
            prev = intervals[i][1];
        }
    }

    return removed;
}