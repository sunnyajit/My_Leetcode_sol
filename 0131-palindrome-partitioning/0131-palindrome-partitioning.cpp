class Solution { // code written by sunny
public:
    bool isPalindrome(string s){
        int N = s.size();
        
        bool flag = true;
        for(int i = 0; i < N/2; i++){
            if(s[i] != s[N-1-i])
                flag = false;
        }
        return flag;
    };
    
    void backtrack(vector<vector<string>>& parts, vector<string>& part, string s, int start){
        if(start >= s.size()){
            parts.push_back(part);
        }else{
            for(int i = 1; start + i <= s.size(); i++){
                string token = s.substr(start, i);
                if(!isPalindrome(token)) continue;
                part.push_back(token);
                backtrack(parts, part, s, start+i);
                part.pop_back();
            }
        }
    };
    
    vector<vector<string>> partition(string s) {
        int N = s.size();
        vector<vector<string>> parts;
        vector<string> part;
        
        backtrack(parts, part, s, 0);
        
        return parts;
    }
};