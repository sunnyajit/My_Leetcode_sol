// #include <unordered_set>
// using namespace std;

// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
// };

class FindElements {
private: // code written by sunny
    unordered_set<int> values; // Store all valid values

    void recover(TreeNode* node, int value) {
        if (!node) return;
        node->val = value;
        values.insert(value);
        recover(node->left, 2 * value + 1);
        recover(node->right, 2 * value + 2);
    }

public:
    FindElements(TreeNode* root) {
        if (root) recover(root, 0); // Start recovery from root with value 0
    }
    
    bool find(int target) {
        return values.count(target);
    }
};































 