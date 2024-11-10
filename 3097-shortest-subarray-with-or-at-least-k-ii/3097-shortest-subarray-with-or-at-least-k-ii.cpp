class Solution {
public: // code written by sunny
    #define ll long long 
    int minimumSubarrayLength(vector<int>& a, int k) {
        vector<int>h(31, -1);
        if(k==0)
            return 1;
        int ans=1e9;
        for(int i=0; i<a.size(); i++){
            for(int j=0; j<=30; j++){
                if(a[i]&(1<<j)){
                    h[j]=i;
                }
            }
            vector<pair<int,int>>v;
            for(int j=0; j<=30; j++){
                if(h[j]!=-1){
                    v.push_back({h[j],j});
                }
            }
            sort(v.begin(), v.end());
            int cans = 0;
            for(int j=v.size()-1; j>=0; j--){
                cans = (cans|(1<<v[j].second));
                if(cans>=k){
                    ans=min(ans,i-v[j].first+1);
                }
            }
        }
        
        if(ans==1e9)
            ans=-1;
        return  ans;
    }
};