 class Solution {
public:// code written by sunny...
     int minKBitFlips(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> isFlipped(n, 0);
    int flipCount = 0;
    int result = 0;

    for (int i = 0; i < n; ++i) {
        if (i >= k) {
            flipCount ^= isFlipped[i - k];
        }
        if (nums[i] == flipCount) {
            if (i + k > n) return -1;
            ++result;
            flipCount ^= 1;
            isFlipped[i] = 1;
        }
    }
    return result;
}

int main() {
    vector<vector<int>> testCases = {
        {0, 1, 0},
        {1, 1, 0},
        {0, 0, 0, 1, 0, 1, 1, 0}
    };
    vector<int> kValues = {1, 2, 3};
    vector<int> expectedResults = {2, -1, 3};

    for (int i = 0; i < testCases.size(); ++i) {
        int result = minKBitFlips(testCases[i], kValues[i]);
        cout << "Test case " << i + 1 << " result: " << result 
             << " (Expected: " << expectedResults[i] << ")" << endl;
    }

    return 0;
}
};