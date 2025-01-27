class Solution {
public: // code written by sunny
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<bool>> isPrerequisite(numCourses, vector<bool>(numCourses, false));
        for (const auto& prereq : prerequisites) {
            isPrerequisite[prereq[0]][prereq[1]] = true;
        } 
        for (int k = 0; k < numCourses; ++k) {
            for (int i = 0; i < numCourses; ++i) {
                for (int j = 0; j < numCourses; ++j) {
                    isPrerequisite[i][j] = isPrerequisite[i][j] || 
                                           (isPrerequisite[i][k] && isPrerequisite[k][j]);
                }
            }
        } 
        vector<bool> result;
        for (const auto& query : queries) {
            result.push_back(isPrerequisite[query[0]][query[1]]);
        }
        
        return result;
    }
};
