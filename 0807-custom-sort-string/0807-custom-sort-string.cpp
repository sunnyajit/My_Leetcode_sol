 class Solution {
public: /// code written by sunny
    string customSortString(string order, string s) {
        map<char, int>mp;
        for(char c: order){
            mp[c]++;
        }
        string extra="";
        for(char c:s){
            if(mp[c]==0) extra+=c;
            else mp[c]++;
        }
        string ans="";
        for(char c: order){
             while(mp[c]>1){
                 ans+=c;
                 mp[c]--;
             }
        }

        return ans+extra;
    }
};