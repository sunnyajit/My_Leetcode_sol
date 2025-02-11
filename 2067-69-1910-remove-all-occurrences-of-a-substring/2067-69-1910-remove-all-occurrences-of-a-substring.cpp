class Solution {
public: // code written by sunny
    string removeOccurrences(string s, string part) {
        size_t pos = s.find(part);
        while (pos != string::npos) {
            s.erase(pos, part.length());
            pos = s.find(part);
        }
        return s;
    }
};
