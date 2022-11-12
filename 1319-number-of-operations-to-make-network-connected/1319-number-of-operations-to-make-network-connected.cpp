class Solution {
public:
    vector<vector<int>>v;
    int n;
    vector<bool>vis;
    void dfs(int node){
        vis[node] = true;
        for(auto it : v[node]){
            if(!vis[it])
                dfs(it);
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {    
        this->n = n;
        if(connections.size() < n - 1)
            return -1;
        v.resize(n);
        vis.resize(n);
        for(auto it : connections){
            v[it[0]].push_back(it[1]);
            v[it[1]].push_back(it[0]);
        }
        
        int components = 0;
        for(int i = 0 ; i < n ; i++){
            if(!vis[i]){
                dfs(i);
                ++components;
            }
        }
        return components - 1;
    }
};