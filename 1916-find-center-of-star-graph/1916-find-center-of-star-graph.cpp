 class Solution {
public: //code written by sunny..
    int findCenter(vector<vector<int>>& edges) {
         // The center node must appear in both of the first two edges.
    if (edges[0][0] == edges[1][0] || edges[0][0] == edges[1][1]) {
        return edges[0][0];
    } else {
        return edges[0][1];
    }
    }
};