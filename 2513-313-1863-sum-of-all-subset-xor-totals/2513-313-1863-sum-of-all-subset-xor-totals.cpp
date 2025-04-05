class Solution {
public:  // code written by sunny
    void dfs(int index, int currentXOR, vector<int>& nums, int& total) {
        if (index == nums.size()) {
            total += currentXOR;
            return;
        } 
        dfs(index + 1, currentXOR ^ nums[index], nums, total); 
        dfs(index + 1, currentXOR, nums, total);
    }
    
    int subsetXORSum(vector<int>& nums) {
        int total = 0;
        dfs(0, 0, nums, total);
        return total;
    }
};
