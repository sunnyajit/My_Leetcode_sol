 class Solution {
public: // code written by sunny
unordered_map<string, vector<int>> memo;
    vector<int> diffWaysToCompute(string expression) {
        if (memo.find(expression) != memo.end()) {
            return memo[expression];
        }
        
        vector<int> result;
    
        for (int i = 0; i < expression.size(); i++) {
            char c = expression[i];
            if (c == '+' || c == '-' || c == '*') {
                vector<int> left = diffWaysToCompute(expression.substr(0, i));
                vector<int> right = diffWaysToCompute(expression.substr(i + 1));
                for (int l : left) {
                    for (int r : right) {
                        if (c == '+') {
                            result.push_back(l + r);
                        } else if (c == '-') {
                            result.push_back(l - r);
                        } else if (c == '*') {
                            result.push_back(l * r);
                        }
                    }
                }
            }
        }
        if (result.empty()) {
            result.push_back(stoi(expression));
        }
        memo[expression] = result;
        return result;
    }
};
