class Solution {
public: // code written by sunny
    int minSteps(int n) {
         if (n == 1) return 0;

    int operations = 0;
    int divisor = 2;
    while (n > 1) {
        while (n % divisor == 0) {
            operations += divisor;
            n /= divisor;
        }
        ++divisor;
    }
    
    return operations;
    }
};
