class Solution {
public: // code written by sunny
    int minSwaps(string s) {
    int balance = 0;  
    int swaps = 0;   
    int needed = 0;   

    for (char ch : s) {
        if (ch == '[') {
            balance++;  
        } else {
            balance--;  
        }
        if (balance < 0) {
            needed++; 
            balance = 0;  
        }
    }
    return (needed + 1) / 2; 
    }
};