class Solution {
public: // code writteb by sunny
    vector<int> postorder(Node* root) {
        vector<int> ans;
        function<void(Node*)> dfs = [&](Node* root) {
            if (!root) {
                return;
            }
            for (auto& child : root->children) {
                dfs(child);
            }
            ans.push_back(root->val);
        };
        dfs(root);
        return ans;
    }
};
