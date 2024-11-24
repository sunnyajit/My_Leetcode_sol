class Solution {
public: // code written by sunny
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        long long totalSum = 0;   
        int minAbs = INT_MAX;    
        int negativeCount = 0;    
 
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int value = matrix[i][j];
                totalSum += abs(value);          
                minAbs = min(minAbs, abs(value));  
                if (value < 0) negativeCount++;   
            }
        }
        if (negativeCount % 2 == 0) {
            return totalSum;
        } else {
            return totalSum - 2 * minAbs;
        }
    }
};

