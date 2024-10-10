 class Solution {
public: // code written by sunny
    int minPatches(vector<int>& nums, int n) {
    long miss = 1;
    int patches = 0;
    int i = 0;
    while (miss <= n) {
        if (i < nums.size() && nums[i] <= miss) {
            miss += nums[i];
            i++;
        } else {
            miss += miss;
            patches++;
        }
    }
    
    return patches;
}
int main() {
    vector<int> nums1 = {1, 3};
    int n1 = 6;
    cout << "Example 1: " << minPatches(nums1, n1) << endl; // Output: 1

    vector<int> nums2 = {1, 5, 10};
    int n2 = 20;
    cout << "Example 2: " << minPatches(nums2, n2) << endl; // Output: 2

    vector<int> nums3 = {1, 2, 2};
    int n3 = 5;
    cout << "Example 3: " << minPatches(nums3, n3) << endl; // Output: 0

    return 0;
  }
};