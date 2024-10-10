class Solution {
public: // code written by sunny;
    int findJudge(int n, vector<vector<int>>& trust) {
    vector<int> inDegree(n + 1, 0);
    vector<int> outDegree(n + 1, 0);

    for (const auto& t : trust) {
        outDegree[t[0]]++;
        inDegree[t[1]]++;
    }

    for (int i = 1; i <= n; ++i) {
        if (inDegree[i] == n - 1 && outDegree[i] == 0) {
            return i;
        }
    }

    return -1;
    }
};
