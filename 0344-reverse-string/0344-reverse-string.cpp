 class Solution {
public: // code written by sunny
    void reverseString(vector<char>& s) {
        int left = 0;
        int right = s.size()-1;
        while(left < right){
            char tmp = s[left];
            s[left++] = s[right];
            s[right--] = tmp; 
        }
    }
};
