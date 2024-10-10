 class Solution {
public: // code written by sunny...
    int numTeams(vector<int>& rating) {
    int n = rating.size();
    int count = 0;
    vector<int> left_smaller(n, 0);
    vector<int> right_greater(n, 0);
    vector<int> left_larger(n, 0);
    vector<int> right_smaller(n, 0);
    for (int j = 0; j < n; ++j) {
        for (int i = 0; i < j; ++i) {
            if (rating[i] < rating[j]) {
                ++left_smaller[j];
            } else if (rating[i] > rating[j]) {
                ++left_larger[j];
            }
        }
        for (int k = j + 1; k < n; ++k) {
            if (rating[k] > rating[j]) {
                ++right_greater[j];
            } else if (rating[k] < rating[j]) {
                ++right_smaller[j];
            }
        }
    }
    for (int j = 0; j < n; ++j) {
        count += left_smaller[j] * right_greater[j];
        count += left_larger[j] * right_smaller[j];
    }
    
    return count;
    }
};