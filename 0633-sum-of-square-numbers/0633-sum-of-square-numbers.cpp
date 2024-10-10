 class Solution {
public: // code written by sunny
    bool judgeSquareSum(int c) {
        long long a = 0; // True case ke liye 
        long long b = static_cast<long long>(sqrt(c));
        while( a <= b){
            long long sumOfSquares = a*a + b*b;
            if(sumOfSquares == c){
                return true;
            } else if(sumOfSquares < c){
                a++;
            } else{
                b--;
            }
        }

        return false; // boolean type ke data ke liye true or false hi output me
    }
};