class Solution
{ // code written by sunny
public:
    int sum = 0;
    int sumOfLeftLeaves(TreeNode *root)
    {
        if (!root)
            return sum;
        if (root->left and !root->left->left and !root->left->right)
            sum += root->left->val;
        if (root->left)
            sumOfLeftLeaves(root->left);
        if (root->right)
            sumOfLeftLeaves(root->right);
        return sum;
    }
};
