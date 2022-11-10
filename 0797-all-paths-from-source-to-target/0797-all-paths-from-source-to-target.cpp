class Solution {
public:
    vector<vector<int>>ret;
    int dest;
    vector<int>v;
    void dfs(int node , vector<vector<int>>&g){
        if(node == dest){
            return void(ret.push_back(v));
        }
        for(auto it : g[node]){
            v.push_back(it);
            dfs(it , g);
            v.pop_back();
        }
        return;
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        v.push_back(0);
        dest = graph.size() - 1;
        dfs(0 , graph );
        return ret;
    }
};