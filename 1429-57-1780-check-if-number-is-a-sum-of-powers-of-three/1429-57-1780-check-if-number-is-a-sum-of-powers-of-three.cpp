class Solution {
public: // code written by sunny
    bool checkPowersOfThree(int n) {
        while (n > 0) {
            if (n % 3 == 2) return false;   
            n /= 3;  
        }
        return true;
    }
};
