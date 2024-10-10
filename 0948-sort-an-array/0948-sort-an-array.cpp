 class Solution {
public: // code written by sunny...
    vector<int> sortArray(vector<int>& subs) {
        int dec = *min_element(begin(subs), end(subs));
        int inc = *max_element(begin(subs), end(subs));
        unordered_map<int, int> mp;
        for(int &sub : subs)
            mp[sub]++;
        int j = 0;
        for(int sub = dec; sub<= inc; sub++) {
            while(mp[sub] > 0) {
                subs[j] = sub;
                j++;
                mp[sub]--;
            }
            
        }
        
        return subs;
    }
};