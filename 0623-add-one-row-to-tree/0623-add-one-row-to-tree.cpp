 class Solution
{ // code written by sunny
public:
    TreeNode *addOneRow(TreeNode *root, int val, int depth)
    {
        if (depth == 1)
        {
            TreeNode *newNode = new TreeNode(val);
            newNode->left = root;
            return newNode;
        }
        queue<TreeNode *> q;
        q.push(root);
        int count = 0;
        while (!q.empty())
        {
            int n = q.size();
            count++;
            for (int i = 0; i < n; i++)
            {
                TreeNode *curr = q.front();
                q.pop();
                if (count != depth - 1)
                {
                    if (curr->left)
                        q.push(curr->left);
                    if (curr->right)
                        q.push(curr->right);
                }
                else
                {
                    TreeNode *leftNode = new TreeNode(val);
                    leftNode->left = curr->left;
                    curr->left = leftNode;
                    TreeNode *rightNode = new TreeNode(val);
                    rightNode->right = curr->right;
                    curr->right = rightNode;
                }
            }
        }
        return root;
    }
};
