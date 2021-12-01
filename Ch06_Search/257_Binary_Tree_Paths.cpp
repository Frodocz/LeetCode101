/**
 * 6.5 Basic Practices 2
 * 257. Binary Tree Paths(Easy)
 * 
 * Given the root of a binary tree, return all root-to-leaf paths in any order.
 * A leaf is a node with no children.
 * 
 * 
 * Input: root = [1,2,3,null,5]
 * Output: ["1->2->5","1->3"]
 * 
 * Input: root = [1]
 * Output: ["1"]
 * 
 * 
 * Constraints:
 *  * The number of nodes in the tree is in the range [1, 100].
 *  * -100 <= Node.val <= 100
 * 
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> ans;
    if(!root) return ans;
    dfs(root, to_string(root->val), ans);
    return ans;
}

void dfs(TreeNode* curr, string curPath, vector<string> &ans) {
    if (!curr->left && !curr->right) {
        ans.push_back(curPath);
        return;
    }

    if (curr->left) dfs(curr->left, curPath + "->" + to_string(curr->left->val), ans);
    if (curr->right) dfs(curr->right, curPath + "->" + to_string(curr->right->val), ans);
}
