 class Solution {
public: // code written by sunny
    int lengthOfLastWord(string s) {
        int length =0;
        int i=s.length()-1;
        // skip trailing space..
        while(i>=0 && s[i]== ' '){
            i--;
        }
        // count the character of the last word..
        while(i>=0 && s[i]!=' '){
            length++;
            i--;
        }

        return length;
    }
};