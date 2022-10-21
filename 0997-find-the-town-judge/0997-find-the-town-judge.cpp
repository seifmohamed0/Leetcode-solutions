class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<vector<int>>v(n + 1);
        for(auto it : trust){
            v[it[1]].push_back(it[0]);
        }
        int judge = -1;
        for(int i = 1 ; i <= n ; i++){
            if(v[i].size() == n - 1){
                judge = i ;
                break;
            }
        }
        if(judge == -1)
            return -1;
        for(auto it : trust)
            if(it[0] == judge)
                return -1;
        return judge;
    }
};