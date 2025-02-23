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
    unordered_map<int, int> postIndexMap;
    int preIndex = 0;

    TreeNode* constructTree(vector<int>& preorder, vector<int>& postorder, int left, int right) {
        if (preIndex >= preorder.size() || left > right) return nullptr;

        TreeNode* root = new TreeNode(preorder[preIndex++]);

        if (preIndex >= preorder.size() || left == right) return root;

        int leftRootIndex = postIndexMap[preorder[preIndex]];

        root->left = constructTree(preorder, postorder, left, leftRootIndex);
        root->right = constructTree(preorder, postorder, leftRootIndex + 1, right - 1);

        return root;
    }

    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        for (int i = 0; i < postorder.size(); i++) {
            postIndexMap[postorder[i]] = i;
        }
        return constructTree(preorder, postorder, 0, postorder.size() - 1);
    }
};
