/**
 * 6.5 Advanced Practices 4
 * 310. Minimum Height Trees(Medium)
 * 
 * A tree is an undirected graph in which any two vertices are connected by exactly one path. In other words, any connected graph without simple cycles is a tree.
 * 
 * Given a tree of n nodes labelled from 0 to n - 1, and an array of n - 1 edges where edges[i] = [ai, bi] indicates that 
 * there is an undirected edge between the two nodes ai and bi in the tree, you can choose any node of the tree as the root. 
 * When you select a node x as the root, the result tree has height h. 
 * Among all possible rooted trees, those with minimum height (i.e. min(h))  are called minimum height trees (MHTs).
 * 
 * Return a list of all MHTs' root labels. You can return the answer in any order.
 * 
 * The height of a rooted tree is the number of edges on the longest downward path between the root and a leaf.
 * 
 * 
 * Input: n = 4, edges = [[1,0],[1,2],[1,3]]
 * Output: [1]
 * Explanation: As shown, the height of the tree is 1 when the root is the node with label 1 which is the only MHT.
 * 
 * Input: n = 6, edges = [[3,0],[3,1],[3,2],[3,4],[5,4]]
 * Output: [3,4]
 * 
 * Input: n = 1, edges = []
 * Output: [0]
 * 
 * Input: n = 2, edges = [[0,1]]
 * Output: [0,1]
 * 
 * Constraints:
 *  * 1 <= n <= 2 * 10^4
 *  * edges.length == n - 1
 *  * 0 <= ai, bi < n
 *  * ai != bi
 *  * All the pairs (ai, bi) are distinct.
 *  * The given input is guaranteed to be a tree and there will be no repeated edges.
 * 
 */

vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
    if (n == 0) return {};
    if (n == 1) return {0};
    
    vector<int> res;
    vector<vector<int>> adjLists(n);
    vector<int> degrees(n, 0);
    queue<int> q;
    
    for (auto & e: edges) {
        adjLists[e[0]].push_back(e[1]);
        adjLists[e[1]].push_back(e[0]);
        ++degrees[e[0]];
        ++degrees[e[1]];
    }
    
    for (int i = 0; i < n; i++) {
        if (degrees[i] == 1) //adding all the leave nodes
            q.push(i);    
    }
    
    while (!q.empty()) {
        res.clear(); // clear vector before we start traversing level by level.
        int size = q.size();
        for (int i = 0; i < size; i++) {
            int u = q.front(); // u is cur
            q.pop();
            res.push_back(u); //adding nodes to vector.Goal is to get a vector of  just 1 or 2 nodes available.
            for (auto v : adjLists[u]) {
                --degrees[v]; //removing current leave nodes
                if (degrees[v] == 1) { //adding current leave nodes
                    q.push(v);
                }
            }
        }
    }
    
    return res;
}
