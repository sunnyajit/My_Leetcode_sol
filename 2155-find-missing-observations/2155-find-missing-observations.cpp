class Solution {
public: // code written by sunny
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
         int m = rolls.size();
    
    
    int total_sum = mean * (n + m);
     
    int known_sum = std::accumulate(rolls.begin(), rolls.end(), 0);
     
    int missing_sum = total_sum - known_sum;
    
    
    if (missing_sum < n || missing_sum > 6 * n) {
        return {};
    }
     
    vector<int> result(n, 1);
     
    int remaining_sum = missing_sum - n;   
    
    for (int i = 0; i < n && remaining_sum > 0; ++i) {
        int add = min(remaining_sum, 5); 
        result[i] += add;
        remaining_sum -= add;
    }
    
    return result;
    }
};
