 class Solution {
public: // code written by sunnykr.
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> countMap;
        vector<int> result;
        
        // Count the occurrences of each element in nums1
        for (int num : nums1) {
            countMap[num]++;
        }
        
        // For each element in nums2, check if it exists in countMap
        for (int num : nums2) {
            if (countMap[num] > 0) {
                result.push_back(num);
                countMap[num]--;  // Decrease the count in the map
            }
        }
        
        return result;
    }
};