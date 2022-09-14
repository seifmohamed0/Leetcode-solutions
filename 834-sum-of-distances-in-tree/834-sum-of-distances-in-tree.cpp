class Solution {
public:
    void dfs(int node , int par , vector<int>&d , vector<int>&childs , vector<vector<int>>&v){
        int ch = 0 , sum = 0;
        for(auto it : v[node]){
            if(it == par)
                continue;
            dfs(it , node , d , childs , v);
            ch += childs[it];
            sum += d[it];
        }
        childs[node] = ch + 1;
        d[node] = sum + (ch);
    }
    void dfs2(int node , int par , int outer , int nodes , vector<int>&ret , vector<int>&d , vector<int>&childs,
             vector<vector<int>>&v){
        ret[node] = d[node] + outer;
        for(auto it : v[node]){
            if(it == par)
                continue;
            dfs2(it , node , 
            outer +childs[node] - childs[it] + d[node] - d[it] - childs[it] + nodes ,
            nodes + childs[node] - childs[it] , ret , d , childs , v);
        }
        
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<int>d(n) , childs(n);
        vector<vector<int>>v(n);
        for(auto it: edges){
            v[it[0]].push_back(it[1]);
            v[it[1]].push_back(it[0]);
        }
        dfs(0 , 0 , d , childs , v);
        vector<int>ret(n);
        // node parent outer_node_cnt dist
        dfs2(0 , 0 , 0 , 0 , ret , d , childs , v);
        return ret;
    }
};