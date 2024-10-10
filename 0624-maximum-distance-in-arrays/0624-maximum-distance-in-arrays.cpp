 class Solution {
public: // code written by sunny
    int maxDistance(vector<vector<int>>& arrays) {
     int n = arrays.size();
    int global_min = arrays[0][0];
    int global_max = arrays[0].back();
    int result = 0;

    for (int i = 1; i < n; ++i) {
        int local_min = arrays[i][0];
        int local_max = arrays[i].back();

        // Calculate maximum distances using the current array
        result = max(result, abs(local_max - global_min));
        result = max(result, abs(local_min - global_max));

        // Update global min and max
        global_min = min(global_min, local_min);
        global_max = max(global_max, local_max);
    }
    
    return result;
    }
};