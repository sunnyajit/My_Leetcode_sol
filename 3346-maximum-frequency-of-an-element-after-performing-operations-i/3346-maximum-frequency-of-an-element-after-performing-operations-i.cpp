
class Solution {
public: // code written by sunny
    int maxFrequency(std::vector<int>& nums, int k, int numOperations) {
        int maxElement = *std::max_element(nums.begin(), nums.end());
        int arraySize = maxElement + k + 2;  
         vector<int> frequency(arraySize, 0);
        for (int num : nums) {
            frequency[num] += 1;
        }
        std::vector<int> prefixSum(arraySize, 0);
        prefixSum[0] = frequency[0];
        for (int i = 1; i < arraySize; ++i) {
            prefixSum[i] = prefixSum[i - 1] + frequency[i];
        }
        int maxFrequencyResult = 0;
        for (int currentElement = 0; currentElement < arraySize; ++currentElement) {
            if (frequency[currentElement] == 0 && numOperations == 0) {
                continue;
            }
            int leftRange = std::max(0, currentElement - k);
            int rightRange = std::min(arraySize - 1, currentElement + k);
            int totalInRange = prefixSum[rightRange] - (leftRange > 0 ? prefixSum[leftRange - 1] : 0);
            int canAdjust = totalInRange - frequency[currentElement];
            int total = frequency[currentElement] + std::min(numOperations, canAdjust);
            maxFrequencyResult = std::max(maxFrequencyResult, total);
        }

        return maxFrequencyResult;
    }
};
