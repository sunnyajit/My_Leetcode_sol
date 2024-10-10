class Solution {
public: // code written by sunny
    vector<int> postorderTraversal(TreeNode* node) {
        vector<int> result; 
        performPostorder(node, result);  
        return result;
    }

private:
    void performPostorder(TreeNode* node, vector<int>& result) {  
        if (node == nullptr)
            return;

        performPostorder(node->left, result); 
        performPostorder(node->right, result); 
        result.push_back(node->val);  
    }
};