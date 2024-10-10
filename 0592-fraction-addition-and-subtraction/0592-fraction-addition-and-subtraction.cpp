class Solution {
public:
// code written by sunny
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}
void addFraction(int& num1, int& den1, int num2, int den2) {
    num1 = num1 * den2 + num2 * den1;
    den1 = den1 * den2;
    int common = gcd(abs(num1), abs(den1));
    num1 /= common;
    den1 /= common;
}
    string fractionAddition(string expression) {
         int numerator = 0, denominator = 1;  
    int i = 0;
    int n = expression.size();
    while (i < n) {
        int sign = 1;
        if (expression[i] == '+' || expression[i] == '-') {
            sign = (expression[i] == '-') ? -1 : 1;
            i++;
        }
        int num = 0;
        while (i < n && isdigit(expression[i])) {
            num = num * 10 + (expression[i] - '0');
            i++;
        }
        i++; 
        int den = 0;
        while (i < n && isdigit(expression[i])) {
            den = den * 10 + (expression[i] - '0');
            i++;
        }
        
        addFraction(numerator, denominator, sign * num, den);
    }
    return to_string(numerator) + "/" + to_string(denominator);
    }
};