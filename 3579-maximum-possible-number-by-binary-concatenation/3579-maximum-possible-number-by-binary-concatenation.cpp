 class Solution {
public:
// code written by sunny
    int getConcatenatedBinaryValue(vector<int>& nums) {
        string concatenatedBinary = "";
        for (int num : nums) {
            concatenatedBinary += bitset<7>(num).to_string().substr(bitset<7>(num).to_string().find('1'));
        }
        return stoi(concatenatedBinary, nullptr, 2);
    }
    int maxGoodNumber(vector<int>& nums) {
        int maxVal = 0;
        sort(nums.begin(), nums.end());
         
        do {
            int currentVal = getConcatenatedBinaryValue(nums);
            maxVal = max(maxVal, currentVal);  
        } while (next_permutation(nums.begin(), nums.end()));
        
        return maxVal;
    }
};