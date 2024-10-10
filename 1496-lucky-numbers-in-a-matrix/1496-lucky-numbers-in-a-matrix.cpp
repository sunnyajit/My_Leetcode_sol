 class Solution {
public: //  code written by sunny....
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
         
    vector<int> luckyNums;
    int m = matrix.size();
    int n = matrix[0].size();
    
    for (int i = 0; i < m; ++i) {
        // Find minimum element in current row
        int minVal = matrix[i][0];
        int colIndex = 0;
        for (int j = 1; j < n; ++j) {
            if (matrix[i][j] < minVal) {
                minVal = matrix[i][j];
                colIndex = j;
            }
        }
        
        // Check if minVal is the maximum in its column
        bool isMaxInColumn = true;
        for (int k = 0; k < m; ++k) {
            if (matrix[k][colIndex] > minVal) {
                isMaxInColumn = false;
                break;
            }
        }
        
        // If true, minVal is a lucky number
        if (isMaxInColumn) {
            luckyNums.push_back(minVal);
        }
    }
    
    return luckyNums;
}
};