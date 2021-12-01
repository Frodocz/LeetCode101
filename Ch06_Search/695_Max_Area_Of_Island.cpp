/**
 * 6.2 Depth-First Search 1 (DFS)
 * 695. Max Area of Island(Easy)
 * 
 * You are given an m x n binary matrix grid. An island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) 
 * You may assume all four edges of the grid are surrounded by water.
 * 
 * The area of an island is the number of cells with a value 1 in the island.
 * Return the maximum area of an island in grid. If there is no island, return 0.
 * 
 * 
 * Input: grid = [[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,1,1,0,1,0,0,0,0,0,0,0,0],[0,1,0,0,1,1,0,0,1,0,1,0,0],
 * 				  [0,1,0,0,1,1,0,0,1,1,1,0,0],[0,0,0,0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]]
 * Output: 6
 * Explanation: The answer is not 11, because the island must be connected 4-directionally.

 * 
 * Input: grid = [[0,0,0,0,0,0,0,0]], Output: 0
 * 
 * Constraints:
 *  * m == grid.length
 *  * n == grid[i].length
 *  * 1 <= m, n <= 50
 *  * grid[i][j] is either 0 or 1.
 * 
 */

#include <bits/stdc++.h>
using namespace std;

vector<int> dirs{-1, 0, 1, 0, -1};
int maxAreaOfIsland(vector<vector<int>>& grid) {
    int m = grid.size(), n = m ? grid[0].size() : 0, localArea, area = 0, x, y;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j]) {
                localArea = 1;
                grid[i][j] = 0;
                stack<pair<int, int>> island;
                island.push({i, j});
                while (!island.empty()) {
                    auto [r, c] = island.top(); 
                    island.pop();
                    for (int k = 0; k < 4; ++k) {
                        x = r + dirs[k], y = c + dirs[k + 1];
                        if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y]) {
                            island.push({x, y});
                            ++localArea;
                            grid[x][y] = 0;
                        }
                    }
                }
                if (localArea > area) area = localArea;
            }
        }
    }
    return area;
}

// 主函数
int maxAreaOfIsland(vector<vector<int>>& grid) {
    if (grid.empty() || grid[0].empty()) return 0; 
    int maxArea = 0;
    for (int i = 0; i < grid.size(); ++i) {
        for (int j = 0; j < grid[0].size(); ++j) { 
            if (grid[i][j] == 1) {
                maxArea = max(maxArea, dfs(grid, i, j)); 
            }
        } 
    }
    return maxArea; 
}

// 辅函数
int dfs(vector<vector<int>>& grid, int r, int c) {
    if (grid[r][c] == 0) return 0;
    grid[r][c] = 0;
    int x, y, area = 1;
    for (int i = 0; i < 4; ++i) {
        x = r + dirs[i], y = c + dirs[i+1];
        if (x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size()) {
            area += dfs(grid, x, y);
        }
    }
    return area;
}

// 辅函数
int dfs(vector<vector<int>>& grid, int r, int c) {
    if (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size() || grid[r][c] == 0) return 0;
    grid[r][c] = 0;
    return 1 + dfs(grid, r + 1, c) + dfs(grid, r, c + 1) + dfs(grid, r - 1, c) + dfs(grid, r, c - 1);
}
