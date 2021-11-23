/**
 * 2.4 基础练习2
 * 452. Minimum Number of Arrows to Burst Balloons(Medium)
 * 
 * There are some spherical balloons taped onto a flat wall that represents the XY-plane. 
 * The balloons are represented as a 2D integer array points where points[i] = [x_start, x_end] 
 * denotes a balloon whose horizontal diameter stretches between x_start and x_end. 
 * You do not know the exact y-coordinates of the balloons.
 * 
 * Arrows can be shot up directly vertically (in the positive y-direction) from different points along the x-axis. 
 * A balloon with x_start and x_end is burst by an arrow shot at x if x_start <= x <= x_end. 
 * There is no limit to the number of arrows that can be shot. 
 * A shot arrow keeps traveling up infinitely, bursting any balloons in its path.
 * 
 * Given the array points, return the minimum number of arrows that must be shot to burst all balloons.
 * 
 * Input: points = [[10,16],[2,8],[1,6],[7,12]], Output: 2
 * Explanation: The balloons can be burst by 2 arrows:
 *  - Shoot an arrow at x = 6, bursting the balloons [2,8] and [1,6].
 *  - Shoot an arrow at x = 11, bursting the balloons [10,16] and [7,12].
 * 
 * Input: points = [[1,2],[3,4],[5,6],[7,8]], Output: 4
 * Explanation: One arrow needs to be shot for each balloon for a total of 4 arrows.
 * 
 * Input: points = [[1,2],[2,3],[3,4],[4,5]], Output: 2
 * Explanation: The balloons can be burst by 2 arrows:
 *  - Shoot an arrow at x = 2, bursting the balloons [1,2] and [2,3].
 *  - Shoot an arrow at x = 4, bursting the balloons [3,4] and [4,5].
 * 
 * Constraints:
 *  * 1 <= points.length <= 105
 *  * points[i].length == 2
 *  * -2^31 <= x_start < x_end <= 2^31 - 1
 */

#include <bits/stdc++.h>
using namespace std;
// Normal sort by the left interval
int findMinArrowShots(vector<vector<int>>& points) {
    int n = points.size();
    sort(points.begin(), points.end());
    int start = points[0][0], end = points[0][1], ans = 0;
    for (int i = 1; i < n; ++i) {
        auto cur = points[i];
        if (end >= cur[0]) { // Overlap
            // update new interval
            start = max(start, cur[0]), end = min(end, cur[1]);
        } else {
            ++ans; // shoot all previous;
            start = cur[0], end = cur[1];
        }
    }
    // last shoot
    return ++ans;
}

// Sort by the right interval
int findMinArrowShots(vector<vector<int>>& points) {
    if (points.size() == 0) return 0;
    int n = points.size();
    sort(points.begin(), points.end(), [](vector<int>& a, vector<int> &b) {
        return a[1] < b[1];
    });
    int overlapped = 0, prev = points[0][1];
    for (int i = 1; i < n; i++) {
        if (points[i][0] <= prev) overlapped++;
        else prev = points[i][1];
    }
    return n - overlapped;
}
