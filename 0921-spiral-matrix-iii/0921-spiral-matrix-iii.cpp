class Solution {
public: // code written by sunny
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
     vector<vector<int>> result;
    vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int r = rStart, c = cStart;
    result.push_back({r, c});
    int steps = 1;
    int dirIndex = 0;
    int totalCells = rows * cols;
    
    while (result.size() < totalCells) {
   
        for (int i = 0; i < steps; ++i) {
            r += directions[dirIndex][0];
            c += directions[dirIndex][1];
            
            // Check if the new position is within bounds
            if (r >= 0 && r < rows && c >= 0 && c < cols) {
                result.push_back({r, c});
            }
        }
    
        dirIndex = (dirIndex + 1) % 4;
        if (dirIndex % 2 == 0) {
            ++steps;
        }
    }
    
    return result;
    }
};