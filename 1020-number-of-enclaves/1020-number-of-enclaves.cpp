class Solution {
public:
    int n , m;
    bool valid(int x , int y){
        return x >= 0 && x < n && y >= 0 && y < m ;
    }
    int is_bound(int x , int y){
        return x == 0 || y == 0 || x == n - 1 || y == m - 1;
    }
    int xd[4] = {0 , 0 , 1 , -1};
    int yd[4] = {1 , -1 , 0 , 0};
    int numEnclaves(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        queue<array<int,2>>q;
        int ans = 0;
        int cnt = 0;
        bool flag ;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == 1){
                    flag = false;
                    q.push({i , j});
                    grid[i][j] = 0;
                    if(is_bound(i , j))
                        flag = true;
                    cnt = 1;
                    while(!q.empty()){
                        array<int,2>curr = q.front();
                        q.pop();
                        for(int k = 0 ; k < 4 ; k++){
                            int n_x = curr[0] + xd[k];
                            int n_y = curr[1] + yd[k];
                            if(valid(n_x , n_y) && grid[n_x][n_y] == 1){
                                grid[n_x][n_y] = 0;
                                if(!flag && is_bound(n_x , n_y))
                                    flag = true;
                                ++cnt;
                                q.push({n_x , n_y});
                            }
                        }       
                    }
                    if(!flag)
                        ans += cnt;
                }
            }
        }
        return ans;
    }
};