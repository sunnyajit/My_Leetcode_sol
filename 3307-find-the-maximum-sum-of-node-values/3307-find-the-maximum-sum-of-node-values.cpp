 class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        long long result = 0, alt_result = -1e9;
        for (auto n : nums) {
            int alt_n = n ^ k;
            long long tmp = result;
            result = max(result + n, alt_result + alt_n);
            alt_result = max(alt_result + n, tmp + alt_n);
            //cout << result << "," << alt_result << endl;
        }
        return result;
    }
};