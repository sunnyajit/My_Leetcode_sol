 class Solution {
public: // code written by sunny..
    int minOperations(vector<string>& logs) {
        stack<string> st;
        int count = 0;
        
        for (const auto& log : logs) {
            if (log == "../") {
                if (!st.empty()) {
                    st.pop();
                }
            } else if (log == "./") {
                continue; // do nothing, stay in current directory
            } else {
                st.push(log); // move into the child folder
            }
        }
        
        return st.size();
    }
};