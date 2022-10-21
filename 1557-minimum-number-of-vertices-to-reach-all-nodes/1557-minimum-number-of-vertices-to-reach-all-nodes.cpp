class Solution {
public:
    vector<vector<int>>v;
    stack<int>st;
    vector<bool>vis , vis2;
    void dfs(int node){
        vis[node] = true;
        for(auto it: v[node]){
            if(!vis[it])dfs(it);
        }
        st.push(node);
    }
    void dfs2(int node){
        vis[node] = true;
        for(auto it : v[node]){
            if(!vis[it])
                dfs2(it);
        }
    }
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        v.resize(n);
        vis.resize(n);
        for(auto it : edges){
            v[it[0]].push_back(it[1]);
        }
        for(int i = 0 ; i < n; i++){
            if(!vis[i])
                dfs(i);
        }
        vector<int>ret;
        for(int i = 0 ; i < n ; i++)
            vis[i] = 0;
        while(!st.empty()){
            int node = st.top();
            st.pop();
            if(!vis[node]){
                dfs2(node);
                ret.push_back(node);
            }
        }
        return ret;
    }
};