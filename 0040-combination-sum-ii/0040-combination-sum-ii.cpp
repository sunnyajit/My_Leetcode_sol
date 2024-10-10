 class Solution {
public: // code written by sunny...
      void backtrack(vector<int>& candidates, int target, int start, vector<int>& current, vector<vector<int>>& results) {
    if (target == 0) {
        results.push_back(current);
        return;
    }
    for (int i = start; i < candidates.size(); ++i) {
        if (i > start && candidates[i] == candidates[i - 1]) {
            continue;
        }
        if (candidates[i] > target) {
            break;  
        }
        current.push_back(candidates[i]);
        backtrack(candidates, target - candidates[i], i + 1, current, results);
        current.pop_back();
    }
}
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> results;
    vector<int> current;
    sort(candidates.begin(), candidates.end());
    
    backtrack(candidates, target, 0, current, results);
    
    return results;
    }
};