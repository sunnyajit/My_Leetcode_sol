class Solution {
public: // code written by sunny
    int maxChunksToSorted(vector<int>& arr) {
        int maxSoFar = 0;
        int chunks = 0;
        for (int i = 0; i < arr.size(); ++i) {
            maxSoFar = max(maxSoFar, arr[i]);
            if (maxSoFar == i) {
                ++chunks;
            }
        }

        return chunks;
    }
};
