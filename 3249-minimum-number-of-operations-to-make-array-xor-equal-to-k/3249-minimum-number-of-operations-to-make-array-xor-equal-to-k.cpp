  class Solution {
public: // code written by sunny
    int minOperations(vector<int>& nums, int k) {
        return __builtin_popcount(accumulate(cbegin(nums), cend(nums), k, [](int accu, int x) {
            return accu ^ x;
        }));
    }
};