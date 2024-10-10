  class Solution {
public: // code written by sunny
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
         vector<int> values;
    while (head != nullptr) {
        values.push_back(head->val);
        head = head->next;
    }
    
  
    vector<vector<int>> matrix(m, vector<int>(n, -1));
    
    int top = 0, bottom = m - 1, left = 0, right = n - 1;
    int index = 0;
    
    while (top <= bottom && left <= right){
        for (int i = left; i <= right; ++i) {
            if (index < values.size()) matrix[top][i] = values[index++];
        }
        ++top;
        for (int i = top; i <= bottom; ++i) {
            if (index < values.size()) matrix[i][right] = values[index++];
        }
        --right;
        
        if (top <= bottom) {
            for (int i = right; i >= left; --i) {
                if (index < values.size()) matrix[bottom][i] = values[index++];
            }
            --bottom;
        }
        
        if (left <= right) {
            for (int i = bottom; i >= top; --i) {
                if (index < values.size()) matrix[i][left] = values[index++];
            }
            ++left;
        }
    }
    
    return matrix;
    }
};