class Solution {
public:
    int xd[4] = {0 , 0 , 1 , -1};
    int yd[4] = {1 , -1 , 0 , 0};
    int n , m;
    bool valid(int x , int y){
        return x >= 0 && x < n && y >= 0 && y < m;
    }
    int maxDistance(vector<vector<int>>& grid) {
        queue<array<int,2>>q;
        n = grid.size();
        m = grid[0].size();
        vector<vector<int>>dist(n , vector<int>(m));
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j]){
                    q.push({i , j});
                }
            }
        }
        int  ret = -1;
        while(!q.empty()){
            array<int,2>node = q.front();
            q.pop();
            for(int k = 0 ; k < 4 ; k++){
                int n_x = node[0] + xd[k];
                int n_y = node[1] + yd[k];
                if(valid(n_x , n_y) && !grid[n_x][n_y] && !dist[n_x][n_y]){
                    dist[n_x][n_y] = dist[node[0]][node[1]] + 1;
                    ret = max(ret , dist[n_x][n_y]);
                    q.push({n_x , n_y});
                }
            }
        }
        return ret;
    }
};