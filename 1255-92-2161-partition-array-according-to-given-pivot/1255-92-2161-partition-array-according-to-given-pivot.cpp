// #include <bits/stdc++.h>
// using namespace std;

class Solution {
  public: // code written by sunny
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> less, equal, greater;
        for (int num : nums) {
            if (num < pivot) 
                less.push_back(num);
            else if (num == pivot) 
                equal.push_back(num);
            else 
                greater.push_back(num);
        } 
        vector<int> result;
        result.insert(result.end(), less.begin(), less.end());
        result.insert(result.end(), equal.begin(), equal.end());
        result.insert(result.end(), greater.begin(), greater.end());

        return result;
    }
};
