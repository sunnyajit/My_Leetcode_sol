class Solution {
public: // code written by sunny
    int sumOfDigits(int num) {
        int sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }

    int maximumSum(std::vector<int>& nums) {
        std::unordered_map<int, std::vector<int>> digitSumMap;
        
        for (int num : nums) {
            int digitSum = sumOfDigits(num);
            digitSumMap[digitSum].push_back(num);
        }
        
        int maxSum = -1;
        
        for (auto& entry : digitSumMap) {
            std::vector<int>& group = entry.second;
            
            if (group.size() > 1) {
                std::sort(group.begin(), group.end(), std::greater<int>());
                int currentSum = group[0] + group[1];
                maxSum = std::max(maxSum, currentSum);
            }
        }
        
        return maxSum;
    }
};