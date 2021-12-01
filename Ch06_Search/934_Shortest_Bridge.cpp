/**
 * 6.4 Breadth-First Search 1(BFS)
 * 934. Shortest Bridge(Medium)
 * 
 * You are given an n x n binary matrix grid where 1 represents land and 0 represents water.
 * An island is a 4-directionally connected group of 1's not connected to any other 1's. There are exactly two islands in grid.
 * You may change 0's to 1's to connect the two islands to form one island.
 * 
 * Return the smallest number of 0's you must flip to connect the two islands.
 * 
 * 
 * Input: grid = [[0,1],[1,0]]
 * Output: 1
 * 
 * Input: grid = [[0,1,0],[0,0,0],[0,0,1]]
 * Output: 2
 * 
 * Input: grid = [[1,1,1,1,1],[1,0,0,0,1],[1,0,1,0,1],[1,0,0,0,1],[1,1,1,1,1]]
 * Output: 1
 * 
 * 
 * Constraints:
 *  * n == grid.length == grid[i].length
 *  * 2 <= n <= 100
 *  * grid[i][j] is either 0 or 1.
 *  * There are exactly two islands in grid.
 * 
 */

#include <bits/stdc++.h>
using namespace std;

// 主函数
vector<int> dirs{-1, 0, 1, 0, -1};
int shortestBridge(vector<vector<int>>& grid) {
    int level = 0, n = grid.size();
    queue<pair<int, int>> q;
    // dfs寻找第一个岛屿，并把1全部赋值为2 
    bool flipped = false;
    for (int i = 0; i < n; ++i) {
        if (flipped) break;
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] == 1) {
                dfs(q, grid, n, i, j);
                flipped = true;
                break;
            }
        }
    }

    while (!q.empty()) {
        ++level;
        int size = q.size();
        while (size--) {
            auto [r, c] = q.front(); q.pop();
            for (int k = 0; k < 4; ++k) {
                int x = r + dirs[k], y = c + dirs[k + 1];
                if (x >= 0 && x < n && y >= 0 && y < n) {
                    if (grid[x][y] == 2) continue;
                    else if (grid[x][y] == 1) return level;
                    q.push({x, y});
                    grid[x][y] = 2;
                }
            }
        }
    }

    return level;
}

// 辅函数
void dfs(queue<pair<int, int>> &q, vector<vector<int>> &grid, int n, int i, int j) {
    if (i < 0 || j < 0 || i == n || j == n || grid[i][j] == 2) return;
    if (grid[i][j] == 0) {
        q.push({i, j});
        return;
    }
    grid[i][j] = 2;
    for (int k = 0; k < 4; ++k) {
        dfs(q, grid, n, i + dirs[k], j + dirs[k + 1]);
    }
}
