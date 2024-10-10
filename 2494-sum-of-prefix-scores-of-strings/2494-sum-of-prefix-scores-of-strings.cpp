class Solution {
public: // code written by sunny
struct TrieNode {
    unordered_map<char, TrieNode*> children;
    int count;   

    TrieNode() : count(0) {}
};
class Trie {
private:
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }
    void insert(const string& word) {
        TrieNode* node = root;
        for (char ch : word) {
            if (node->children.find(ch) == node->children.end()) {
                node->children[ch] = new TrieNode();
            }
            node = node->children[ch];
            node->count++;
        }
    }
    int calculatePrefixScore(const string& word) {
        TrieNode* node = root;
        int score = 0;
        for (char ch : word) {
            if (node->children.find(ch) == node->children.end()) {
                break;
            }
            node = node->children[ch];
            score += node->count;
        }
        return score;
    }
};

    vector<int> sumPrefixScores(vector<string>& words) {
         Trie trie;
        for (const string& word : words) {
            trie.insert(word);
        }

        vector<int> result;
        for (const string& word : words) {
            result.push_back(trie.calculatePrefixScore(word));
        }

        return result;
    }
};