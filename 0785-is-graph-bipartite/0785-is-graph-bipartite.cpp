class Solution {
public:
    vector<int>color;
    int n ;
    bool dfs(int node , int col , vector<vector<int>>& graph){
        color[node] = col;
        for(auto it : graph[node]){
            if(color[it] && color[it] == col){
                return false;
            }
            if(!color[it]){
                if(!dfs(it , col == 1 ? 2 : 1 , graph))
                    return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        n = graph.size();
        color.resize(n);
        for(int i = 0 ;i < n ; i++){
            if(!color[i]){
                if(!dfs(i , 1 , graph)){
                    return false;
                }
            }
        }
        return true;
    }
};