/**
 * 6.2 Depth-First Search 3 (DFS)
 * 417. Pacific Atlantic Water Flow(Medium)
 * 
 * There is an m x n rectangular island that borders both the Pacific Ocean and Atlantic Ocean. 
 * The Pacific Ocean touches the island's left and top edges, and the Atlantic Ocean touches the island's right and bottom edges.
 * 
 * The island is partitioned into a grid of square cells. 
 * You are given an m x n integer matrix heights where heights[r][c] represents the height above sea level of the cell at coordinate (r, c).
 * 
 * The island receives a lot of rain, and the rain water can flow to neighboring cells directly north, south, east, and west 
 * if the neighboring cell's height is less than or equal to the current cell's height. Water can flow from any cell adjacent to an ocean into the ocean.
 * 
 * Return a 2D list of grid coordinates result where result[i] = [ri, ci] denotes that rain water can flow from cell (ri, ci) to both the Pacific and Atlantic oceans.
 * 
 * 
 * Input: heights = [[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]]
 * Output: [[0,4],[1,3],[1,4],[2,2],[3,0],[3,1],[4,0]]
 * 
 * Input: heights = [[2,1],[1,2]]
 * Output: [[0,0],[0,1],[1,0],[1,1]]
 * 
 * 
 * Constraints:
 *  * m == heights.length
 *  * n == heights[r].length
 *  * 1 <= m, n <= 200
 *  * 0 <= heights[r][c] <= 10^5
 * 
 */

#include <bits/stdc++.h>
using namespace std;

vector<int> dirs{-1, 0, 1, 0, -1};
vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
    vector<vector<int>> ans;

    int m = heights.size(), n = heights[0].size();
    vector<vector<bool>> canReachPacific(m, vector<bool>(n));
    vector<vector<bool>> canReachAtlantic(m, vector<bool>(n));

    for (int i = 0; i < m; ++i) { 
        dfs(heights, canReachPacific, i, 0); 
        dfs(heights, canReachAtlantic, i, n - 1);
    }

    for (int j = 0; j < n; ++j) {
        dfs(heights, canReachPacific, 0, j); 
        dfs(heights, canReachAtlantic, m - 1, j);
    }

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (canReachAtlantic[i][j] && canReachPacific[i][j]) 
                ans.push_back(vector<int>{i, j});
        }
    }

    return ans;
}

void dfs(vector<vector<int>>& heights, vector<vector<bool>>& canReach, int r, int c) {
    if (canReach[r][c]) return;
    int m = heights.size(), n = heights[0].size(), x, y;
    canReach[r][c] = true;
    for (int k = 0; k < 4; ++k) {
        x = r + dirs[k], y = c + dirs[k + 1];
        if (x >= 0 && x < m && y >= 0 && y < n && heights[x][y] >= heights[r][c]) {
            dfs(heights, canReach, x, y);
        }
    }
}