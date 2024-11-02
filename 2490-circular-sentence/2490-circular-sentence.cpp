class Solution {
public: // code written by sunny
    bool isCircularSentence(string sentence) {
         istringstream stream(sentence);
         string word;
         vector<std::string> words;
        while (stream >> word) {
            words.push_back(word);
        }
        int n = words.size();
        for (int i = 0; i < n; ++i) {
            char lastChar = words[i].back();  
            char nextFirstChar = words[(i + 1) % n].front(); 
            if (lastChar != nextFirstChar) {
                return false; 
            }
        }

        return true;
    }
};