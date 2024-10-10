class Solution {
public: // code written by sunny....
    TreeNode *b(vector<TreeNode *> &v, int l, int r) 
    {
        int m; if (l >= r) return NULL;
        TreeNode *n = v[m = (l + r) / 2];
        n->left = b(v, l, m);
        n->right = b(v, m+1, r);
        return n;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<TreeNode *> w; stack<TreeNode *> v; 
        while (root != NULL || !v.empty()) {
            while (root !=  NULL) { v.push(root); root = root->left; } 
            root = v.top(); v.pop();
            w.push_back(root);
            root = root->right;
        }
        return b(w, 0, w.size());
    }
};