 class Solution {
public: // code written by sunny
    TreeNode* reverseOddLevels(TreeNode* root) {
        if (!root) return nullptr;

        std::queue<TreeNode*> q;
        q.push(root);
        bool isOddLevel = false;

        while (!q.empty()) {
            int levelSize = q.size();
            std::vector<TreeNode*> nodesAtLevel;
 
            for (int i = 0; i < levelSize; ++i) {
                TreeNode* node = q.front();
                q.pop();
                nodesAtLevel.push_back(node);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
 
            if (isOddLevel) {
                int left = 0, right = nodesAtLevel.size() - 1;
                while (left < right) {
                    std::swap(nodesAtLevel[left]->val, nodesAtLevel[right]->val);
                    ++left;
                    --right;
                }
            } 
            isOddLevel = !isOddLevel;
        }

        return root;
    }
};
