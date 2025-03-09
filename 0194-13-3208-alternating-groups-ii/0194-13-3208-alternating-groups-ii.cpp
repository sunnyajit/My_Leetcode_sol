class Solution {
 public: // code written by sunny
  int numberOfAlternatingGroups(vector<int>& colors, int k) {
    const int d = colors.size(); 
    int ans = 0;
    int alt = 1;   
    for (int j = 0; j < d + k - 2; ++j) {   
      alt = colors[j % d] == colors[(j - 1 + d) % d] ? 1 : alt + 1;
      if (alt >= k)
        ++ans;
    }
    return ans;
  }
};
