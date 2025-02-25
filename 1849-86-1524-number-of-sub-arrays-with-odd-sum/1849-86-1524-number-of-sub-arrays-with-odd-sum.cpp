class Solution {
public: // code written by sunny
    int numOfSubarrays(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        long long odd_count = 0, even_count = 1;  
        long long prefix_sum = 0, result = 0;

        for (int num : arr) {
            prefix_sum += num;

            if (prefix_sum % 2 == 0) {
                result = (result + odd_count) % MOD;
                even_count++;
            } else {
                result = (result + even_count) % MOD;
                odd_count++;
            }
        }
        return result;
    }
};
