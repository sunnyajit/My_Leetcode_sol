class Solution {
public: // code written by sunny
char nextChar(char c) {
    return (c == 'z') ? 'a' : c + 1;
}
    char kthCharacter(int k) {
         string word = "a";
    while (word.length() < k) {
        string nextWord = "";
        for (char c : word) {
            nextWord += nextChar(c);  
        }
        word += nextWord; 
    }
    return word[k - 1];
    }
};