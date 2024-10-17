 class Solution {
public: // code written by sunny
    int generateKey(int num1, int num2, int num3) {
    string str1 =  to_string(num1);
     string str2 = to_string(num2);
    string str3 =  to_string(num3);
    str1.insert(0, 4 - str1.size(), '0');
    str2.insert(0, 4 - str2.size(), '0');
    str3.insert(0, 4 - str3.size(), '0');
    string key = "";
    for (int i = 0; i < 4; ++i) {
        key += min({str1[i], str2[i], str3[i]});
    }
    return  stoi(key);
    }
};