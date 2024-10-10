class Solution {
public: // code written by sunny
    bool lemonadeChange(vector<int>& bills) {
         int fiveCount = 0;
    int tenCount = 0;

    for (int bill : bills) {
        if (bill == 5) {
            fiveCount++;
        } else if (bill == 10) {
            if (fiveCount > 0) {
                fiveCount--;
                tenCount++;
            } else {
                return false;
            }
        } else if (bill == 20) {
            if (tenCount > 0) {
                if (fiveCount > 0) {
                    tenCount--;
                    fiveCount--;
                } else {
                    return false;
                }
            } else if (fiveCount >= 3) {
                fiveCount -= 3;
            } else {
                 
                return false;
            }
        }
    }
    
    return true;
    }
};