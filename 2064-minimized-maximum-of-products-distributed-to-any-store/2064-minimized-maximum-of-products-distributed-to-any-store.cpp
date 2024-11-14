class Solution {
public: // code written by sunny
    int minimizedMaximum(int n, std::vector<int>& quantities) {
        int left = 1, right = *std::max_element(quantities.begin(), quantities.end());
        auto canDistribute = [&](int x) {
            int stores_needed = 0;
            for (int quantity : quantities) {
                stores_needed += (quantity + x - 1) / x;  
                if (stores_needed > n) return false;  
            }
            return stores_needed <= n;
        };
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (canDistribute(mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};
