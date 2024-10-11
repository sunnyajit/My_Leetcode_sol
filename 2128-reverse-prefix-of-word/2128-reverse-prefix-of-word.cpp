 class Solution {
 public: // code written by sunny
  string reversePrefix(string word, char ch) {
    reverse(word.begin(), word.begin() + word.find(ch) + 1);
    return word;
  }
};