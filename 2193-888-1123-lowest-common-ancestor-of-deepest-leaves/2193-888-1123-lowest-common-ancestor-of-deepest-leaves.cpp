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
class Solution {
public: // code written by sunny
    pair<int, TreeNode*> dfs(TreeNode* root) {
        if (!root) return {0, nullptr};   
        
        auto left = dfs(root->left);
        auto right = dfs(root->right);

        int leftDepth = left.first, rightDepth = right.first; 
        if (leftDepth == rightDepth) 
            return {leftDepth + 1, root}; 
        return (leftDepth > rightDepth) ? make_pair(leftDepth + 1, left.second)
                                        : make_pair(rightDepth + 1, right.second);
    }

    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return dfs(root).second;
    }
};
