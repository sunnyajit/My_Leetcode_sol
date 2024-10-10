  class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> superset={{},{nums[0]}};
        for(int i=1;i<nums.size();i++){
           vector<vector<int>> curr=superset;
            for(auto vec : curr){
                vec.push_back(nums[i]);
                superset.push_back(vec);
            }
        }
        return superset;
    }
};