class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<array<int,2>>q;
        int xd[] = {0 , 0 , 1 , -1};
        int yd[] = {1 , -1 , 0 ,0};
        int ret = 0;
        vector<vector<bool>>vis(n , vector<bool>(m));
        for(int i = 0; i < n ; i++){
            for(int j = 0; j < m ; j++){
                if(grid[i][j] == '1' && !vis[i][j]){
                    ++ret;
                    q.push({i , j});
                    vis[i][j] = true;
                    while(!q.empty()){
                        array<int,2>curr = q.front();
                        q.pop();
                        for(int k = 0; k < 4 ; k++){
                            int n_x = curr[0] + xd[k] ;
                            int n_y = curr[1] + yd[k];
                            if(n_x >= 0 && n_x < n && n_y >= 0 && n_y < m &&
                               grid[n_x][n_y] == '1' && !vis[n_x][n_y]){
                                q.push({n_x , n_y});
                                vis[n_x][n_y] = true;
                            }
                        }
                    }
                }
            }
        }
        return ret;        
    }
};