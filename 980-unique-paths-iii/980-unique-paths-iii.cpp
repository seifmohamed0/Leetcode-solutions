class Solution {
public:
    int xd[4] = {1 , -1 , 0 , 0};
    int yd[4] = {0 , 0 , 1 , -1};
    int ret = 0 , n , m;
    int Empt = 0;
    array<int,2>Start , End;
    bool valid(int x , int y){
        return x >= 0 && x < n && y >= 0 && y < m;
    }
    void solve(vector<vector<int>>& grid , array<int,2>pos , int empt){
        if(!valid(pos[0] , pos[1]))
            return;
        if(pos == End){
            if(!empt){
                ++ret;
            }
            return;
        }
        for(int i = 0; i < 4 ; i++){
            array<int,2>new_pos = {pos[0] + xd[i] , pos[1] + yd[i]};
            if(!valid(new_pos[0] , new_pos[1]))
                continue;
            if(!grid[new_pos[0]][new_pos[1]]){
                grid[new_pos[0]][new_pos[1]] = -1;
                solve(grid,new_pos,empt-1);
                grid[new_pos[0]][new_pos[1]] = 0;
            }else if(grid[new_pos[0]][new_pos[1]] == 2){
                solve(grid,new_pos,empt);
            }
        }
        return;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        for(int i = 0; i < n ; i++){
            for(int j =0 ; j < m ; j++){
                if(grid[i][j] == 1){
                    Start[0] = i;
                    Start[1] = j;
                }else if(grid[i][j] == 2){
                    End[0] = i;
                    End[1] = j;
                }else if(grid[i][j] == 0){
                    Empt++;
                }
            }
        }
        solve(grid , Start , Empt);
        return ret;
    }
};