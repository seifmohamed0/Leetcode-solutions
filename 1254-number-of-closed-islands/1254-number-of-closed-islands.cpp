class Solution {
public:
     int n , m;
    int xd[4] = {0 , 0 , 1 , -1};
    int yd[4] = {1 , -1 , 0 , 0};
    bool valid(int x , int y){
        return x >= 0 && x < n && y >= 0 && y < m;
    }
    int closedIsland(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        
        vector<vector<bool>>not_valid(n , vector<bool>(m));
        queue<array<int,2>>q;
        
        for(int i = 0 ; i < n ; i++){
            if(grid[i][0] == 0){
                q.push({i , 0});
                not_valid[i][0] = true;
            }
            if(grid[i][m - 1] == 0){
                q.push({i , m - 1});
                not_valid[i][m - 1] = true;
            }
        }
        for(int j = 0 ; j < m; j++){
            if(grid[0][j] == 0){
                q.push({0 , j});
                not_valid[0][j] = true;
            }
            if(grid[n - 1][j] == 0){
                q.push({n - 1 , j});
                not_valid[n-1][j] = true;
            }
        }
        while(!q.empty()){
            array<int,2>node = q.front();
            q.pop();
            for(int k = 0 ; k < 4 ; k++){
                array<int,2>new_node = {node[0] + xd[k] , node[1] + yd[k]};
                if(valid(new_node[0] , new_node[1]) && grid[new_node[0]][new_node[1]] == 0 
                   && !not_valid[new_node[0]][new_node[1]]){
                    not_valid[new_node[0]][new_node[1]] = true;
                    q.push(new_node);
                }
            }
        }
        int ret = 0;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == 0 && !not_valid[i][j]){
                    q.push({i , j});
                    not_valid[i][j] = true;
                    while(!q.empty()){
                        array<int,2>node = q.front();
                        q.pop();
                        for(int k = 0 ; k < 4 ; k++){
                            array<int,2>new_node = {node[0] + xd[k] , node[1] + yd[k]};
                            if(valid(new_node[0] , new_node[1]) && grid[new_node[0]][new_node[1]] == 0 
                                && !not_valid[new_node[0]][new_node[1]]){
                             not_valid[new_node[0]][new_node[1]] = true;
                             q.push(new_node);
                         }       
                        }
                    }
                    ++ret;
                }
            }
        }
        return ret;  
    }
};