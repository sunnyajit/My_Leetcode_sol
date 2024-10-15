 class Solution {  
public: // code written by sunny
    long long minimumSteps(string s) {
        int n = s.length();
        long long totalSwaps = 0;
        int blackBallsCount = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] == '0') {  
                totalSwaps += blackBallsCount; 
            } else {  
                blackBallsCount++;
            }
        }
        return totalSwaps;
    }
};