 class Solution {
public: // code written by sunny
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long res=0;
        queue<int> q;
        int minInd  = -1, maxInd = -1;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]<=maxK && nums[i]>=minK){
                q.push(nums[i]);
                if(nums[i]==minK) minInd = q.size();
                if(nums[i]==maxK) maxInd = q.size();
                if(minInd !=-1 && maxInd !=-1){
                    res+=min(minInd, maxInd);

                }
            }
            else{
                while(!q.empty()) q.pop();
                minInd = -1;
                maxInd = -1;
            }
        } 

        return res;
    }
};