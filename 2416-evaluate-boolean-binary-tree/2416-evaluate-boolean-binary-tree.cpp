 class Solution{
    public: // code written by sunny
    bool evaluateTree(TreeNode* root){
           
             if(root->left==NULL && root->right==NULL){
                return root->val;
             }
        int a = evaluateTree(root->left);
        int b = evaluateTree(root->right);
        if(root->val==2){
            return a | b;
        }
        return a & b;

    }
};