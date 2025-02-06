class Solution {
public: // code written by sunny
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int, int> product_map;
        int n = nums.size();
        int count = 0; 
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int product = nums[i] * nums[j];
                product_map[product]++;
            }
        } 
        for (auto& [product, freq] : product_map) {
            if (freq > 1) {
                count += 8 * (freq * (freq - 1)) / 2;
            }
        }

        return count;
    }
};
