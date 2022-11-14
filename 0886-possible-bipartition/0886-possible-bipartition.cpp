class Solution {
public:
    vector<vector<int>>adj;
    vector<int>color;
    bool dfs(int node , int col){
        color[node] = col;
        bool ret = true;
        for(auto it : adj[node]){
            if(color[it] && color[it] == col){
                ret =false;
                break;
            }
            if(!color[it])
                dfs(it , col == 1 ? 2 : 1);
        }
        return ret;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        adj.resize(n + 1);
        color.resize(n + 1);
        for(auto it : dislikes){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        for(int i = 1 ; i <= n ; i++){
            if(!color[i]){
                if(!dfs(i , 1)){
                    return false;
                }
            }
        }
        return true;
    }
};