class Solution {
public: //  code written by sunny
    bool areSentencesSimilar(string sentence1,  string sentence2) {
         istringstream stream1(sentence1);
         istringstream stream2(sentence2);
        vector<string> words1, words2;
         string word;
        while (stream1 >> word) {
            words1.push_back(word);
        }
        while (stream2 >> word) {
            words2.push_back(word);
        }
        
        int i = 0, j = 0;
        while (i < words1.size() && i < words2.size() && words1[i] == words2[i]) {
            i++;
        }
        while (j < (words1.size() - i) && j < (words2.size() - i) && words1[words1.size() - 1 - j] == words2[words2.size() - 1 - j]) {
            j++;
        }
        return (i + j) >= std::min(words1.size(), words2.size());
    }
};
