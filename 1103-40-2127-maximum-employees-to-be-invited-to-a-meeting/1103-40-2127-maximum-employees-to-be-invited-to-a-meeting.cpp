class Solution {
public: // code written by sunny
    int maximumInvitations(vector<int>& favorite) {
        int n = favorite.size();
        vector<int> inDegree(n, 0);
        vector<bool> visited(n, false);
        vector<int> longestChain(n, 0);
        for (int i = 0; i < n; ++i) {
            inDegree[favorite[i]]++;
        } 
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            visited[node] = true;

            int next = favorite[node];
            longestChain[next] = max(longestChain[next], longestChain[node] + 1);
            if (--inDegree[next] == 0) {
                q.push(next);
            }
        } 
        int maxCycle = 0, chainSum = 0;
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                int cycleLength = 0, curr = i; 
                while (!visited[curr]) {
                    visited[curr] = true;
                    curr = favorite[curr];
                    cycleLength++;
                }

                if (cycleLength == 2) {  
                    int a = i, b = favorite[i];
                    chainSum += 2 + longestChain[a] + longestChain[b];
                } else {
                    maxCycle = max(maxCycle, cycleLength);
                }
            }
        }

        return max(maxCycle, chainSum);
    }
};
