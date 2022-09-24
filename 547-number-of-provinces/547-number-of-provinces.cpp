class Solution {
public:
    int par[201];
    int find_par(int node){
        return par[node] == node ? node : find_par(par[node]);
    }
    void Connect(int u , int v){
        u = find_par(u);
        v = find_par(v);
        return void(par[u] = v);
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        for(int i = 1 ; i <= n  ;i++)
            par[i] = i;
        for(int i = 0; i < n ; i++){
            for(int j = 0; j < n ; j++){
                if(isConnected[i][j]){
                    Connect(i + 1 , j + 1);
                }
            }
        }
        set<int>st;
        for(int i = 1; i <= n ; i++){
            st.insert(find_par(i));
        }
        return (int)st.size();
    }
};