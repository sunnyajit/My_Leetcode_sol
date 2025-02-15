class Solution { 
public: // code written by sunny
    bool checkPartition(const std::string& numStr, int target, int idx, int currentSum) {
        if (idx == numStr.size()) {
            return currentSum == target;
        }
        
        int partNum = 0;
        for (int i = idx; i < numStr.size(); ++i) {
            partNum = partNum * 10 + (numStr[i] - '0');
            if (currentSum + partNum > target) {
                break;  
            }
            if (checkPartition(numStr, target, i + 1, currentSum + partNum)) {
                return true;
            }
        }
        
        return false;
    }

    int punishmentNumber(int n) {
        int result = 0;
        
        for (int i = 1; i <= n; ++i) {
            int square = i * i;
           string squareStr =  to_string(square);
            
            if (checkPartition(squareStr, i, 0, 0)) {
                result += square;
            }
        }
        
        return result;
    }
};
