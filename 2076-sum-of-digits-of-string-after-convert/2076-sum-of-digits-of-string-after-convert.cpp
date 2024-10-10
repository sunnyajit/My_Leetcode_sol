class Solution {
public:  // code written by sunny
string convertStringToNumberString(const string& s) {
    string numStr;
    for (char ch : s) {
        int pos = ch - 'a' + 1;
        numStr += to_string(pos);
    }
    return numStr;
}
int sumOfDigits(const string& numStr) {
    int sum = 0;
    for (char ch : numStr) {
        sum += ch - '0';
    }
    return sum;
}

    int getLucky(string s, int k) {
         string numStr = convertStringToNumberString(s);
    int result = 0;
    for (int i = 0; i < k; ++i) {
        result = sumOfDigits(numStr);
        numStr = to_string(result);
    }
    
    return result;
    }
};