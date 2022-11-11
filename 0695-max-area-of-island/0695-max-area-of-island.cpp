class Solution {
public:
    int xd[4] = {0 , 0 , 1 , -1};
    int yd[4] = {1 , -1 , 0 , 0};
    int n , m ;
    bool valid(int x , int y){
        return x >= 0 && x < n && y >= 0 && y < m;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int ret = 0;
        for(int i = 0; i < n ; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 0)
                    continue;
                queue<array<int,2>>q;
                int cnt = 1;
                q.push({i , j});
                grid[i][j] = 0;
                while(!q.empty()){
                    array<int,2>curr = q.front();
                    q.pop();
                    for(int k = 0; k < 4 ; k++){
                        int n_i = curr[0] + xd[k];
                        int n_j = curr[1] + yd[k];
                        if(valid(n_i , n_j) && grid[n_i][n_j]){
                            grid[n_i][n_j] = 0;
                            q.push({n_i , n_j});
                            ++cnt;
                        }
                        
                    }
                }
                ret = max(ret , cnt);
            }
        }
        return ret;
    }
};