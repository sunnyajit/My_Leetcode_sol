class Solution {
public: // code witten by sunny
    long long countBadPairs(std::vector<int>& nums) {
        unordered_map<long long, long long> count_map;
        long long bad_pairs = 0;
        long long total_pairs = 0;

        for (int i = 0; i < nums.size(); i++) {
            long long diff = i - nums[i]; 
            total_pairs += i; 
            if (count_map.find(diff) != count_map.end()) {
                bad_pairs += count_map[diff];
            } 
            count_map[diff]++;
        }

        return total_pairs - bad_pairs;
    }
};
