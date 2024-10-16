class Solution {
 public: // code written by sunny
  long long maximumHappinessSum(vector<int>& happiness, int k) {
    long long ans = 0;
    int decremented = 0;

    ranges::sort(happiness, greater<>());

    for (int i = 0; i < k; ++i) {
      ans += max(0, happiness[i] - decremented);
      ++decremented;
    }

    return ans;
  }
};