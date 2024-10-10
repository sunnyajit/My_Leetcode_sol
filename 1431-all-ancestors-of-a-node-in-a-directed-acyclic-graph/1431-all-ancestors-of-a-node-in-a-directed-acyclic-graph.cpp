 class Solution {
public: // code written  by sunny
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>>graph;
        for(auto x : edges){
            graph[x[0]].push_back(x[1]);
        }
        vector<vector<int>>res(n);
        for(int j=0; j<n; j++){
            dfs(graph,j,j,res);
        }
        return res;
    }
    void dfs(unordered_map<int, vector<int>>&graph, int anscestor, int node, vector<vector<int>>&res){
        vector<int>child = graph[node];
        for(auto x : child){
            if(res[x].size()==0 || res[x].back()!=anscestor){
                res[x].push_back(anscestor);
                dfs(graph, anscestor, x,res);
            }
        }
        return ;
    }
};