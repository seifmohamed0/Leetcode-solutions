class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<vector<int>>v(n);
        vector<vector<bool>>con(n , vector<bool>(n));
        for(auto it : roads){
            v[it[0]].push_back(it[1]);
            v[it[1]].push_back(it[0]);
            con[it[0]][it[1]] = con[it[1]][it[0]] = true;
        }
        int ret = 0;
        for(int i = 0; i < n ; i++){
            for(int j = i + 1; j < n ; j++){
                int sum = v[i].size() + v[j].size() - (con[i][j]);
                ret = max(ret , sum);   
            }
        }
        return ret;
    }
};