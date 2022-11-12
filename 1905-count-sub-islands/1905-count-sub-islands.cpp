class Solution {
public:
    int n , m;
    int xd[4] = {0 , 0 , 1 , -1};
    int yd[4] = {1 , -1 , 0 , 0};
    bool valid(int x , int y){
        return x >= 0 && x < n && y >= 0 && y < m;
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        n = grid1.size();
        m = grid1[0].size();
        int id = 1;
        queue<array<int,2>>q;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid1[i][j] == 1){
                    ++id;
                    q.push({i , j});
                    grid1[i][j] = id;
                    while(!q.empty()){
                        array<int,2>curr = q.front();
                        q.pop();
                        for(int k = 0 ; k < 4 ; k++){
                            int n_x = curr[0] + xd[k];
                            int n_y = curr[1] + yd[k];
                            if(valid(n_x , n_y) && grid1[n_x][n_y] == 1){
                                grid1[n_x][n_y] = id;
                                q.push({n_x , n_y});
                            }
                        }
                    }
                }
            }
        }
        int ret = 0;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid2[i][j] == 1){
                    bool flag = true;
                    int curr_id = grid1[i][j];
                    if(!curr_id)flag = false;
                    q.push({i , j});
                    grid2[i][j] = 0;
                    while(!q.empty()){
                        array<int,2>curr = q.front();
                        q.pop();
                        for(int k = 0 ; k < 4 ; k++){
                            int n_x = curr[0] + xd[k];
                            int n_y = curr[1] + yd[k];
                            if(valid(n_x , n_y) && grid2[n_x][n_y] == 1){
                               if(grid1[n_x][n_y] != curr_id)flag = false;
                                grid2[n_x][n_y] = 0;
                                q.push({n_x , n_y});
                            }
                        }
                    }
                    if(flag)++ret;
                }
            }
        }
        return ret;
    }
};