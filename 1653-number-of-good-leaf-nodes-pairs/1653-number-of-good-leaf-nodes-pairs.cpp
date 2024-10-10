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
public: // code written by sunny....
    int countPairs(TreeNode* root, int distance) {
        int result = 0;
        dfs(root, distance, result);
        return result;
    }

private:
    // Helper function for DFS traversal
    vector<int> dfs(TreeNode* node, int distance, int &result) {
        if (!node) return {};
        if (!node->left && !node->right) return {1};

        vector<int> leftDistances = dfs(node->left, distance, result);
        vector<int> rightDistances = dfs(node->right, distance, result);

        // Count good pairs
        for (int ld : leftDistances) {
            for (int rd : rightDistances) {
                if (ld + rd <= distance) {
                    result++;
                }
            }
        }

        // Collect distances for the current node
        vector<int> currentDistances;
        for (int ld : leftDistances) {
            if (ld + 1 <= distance) currentDistances.push_back(ld + 1);
        }
        for (int rd : rightDistances) {
            if (rd + 1 <= distance) currentDistances.push_back(rd + 1);
        }

        return currentDistances;
    }
};

 