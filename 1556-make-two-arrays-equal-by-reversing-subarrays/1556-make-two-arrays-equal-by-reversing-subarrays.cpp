 class Solution {
public: // code written by sunny..
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
    sort(target.begin(), target.end());
    sort(arr.begin(), arr.end());
    return target == arr;
    }
};