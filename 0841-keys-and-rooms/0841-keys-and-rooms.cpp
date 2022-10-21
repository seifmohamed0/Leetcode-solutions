class Solution {
public:
    vector<bool>vis;
    int n;
    void dfs(int node,vector<vector<int>>& rooms){
        vis[node] = true;
        for(auto it : rooms[node])
            if(!vis[it])
                dfs(it,rooms);
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        n = rooms.size();
        vis.resize(n);
        dfs(0,rooms);
        for(int i = 0 ; i < n ; i++)
            if(!vis[i])return false;
        return true;
    }
};