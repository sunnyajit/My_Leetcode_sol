 class Solution {
public: // code written by sunny
    vector<string> solve(string s, int i, vector<string>& wordDict){
        if(i==s.size()) return {""};
        vector<string> ans;
        string temp;
        for(int j=i;j<s.size();j++){
            temp+=s[j];
            if(find(wordDict.begin(), wordDict.end(), temp)!=wordDict.end()){
                vector<string> a=solve(s,j+1,wordDict);
                for(auto str: a){
                    if(str=="") ans.push_back(temp);
                    else ans.push_back(temp+' '+ str);
                }
            }
        }
        return ans;
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        return solve(s,0,wordDict);
    }
};