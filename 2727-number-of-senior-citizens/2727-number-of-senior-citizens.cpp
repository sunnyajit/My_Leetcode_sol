 class Solution {
public: // code written by sunny..
    int countSeniors(vector<string>& details) {
        int count = 0;
    for (const std::string& detail : details) {
        string ageStr = detail.substr(11, 2);
        int age = stoi(ageStr);
        if (age > 60) {
            count++;
        }
    }

    return count;
    }
};