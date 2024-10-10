class Solution {
 public: // codd written by sunny...
  int minimumPushes(string seq) {
    int sol = 0;
    vector<int> cnt(20+6);
    for (const char t: seq)
      ++cnt[t - 'a'];
    ranges::sort(cnt, greater<>());
    for (int j = 0; j < 26; ++j)
      sol += cnt[j] * (j / 8 + 1);
    return sol;
  }
};