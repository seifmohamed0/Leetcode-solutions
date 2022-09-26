class Solution {
public:
    int xd[8] = {0 , 0 , 1 , -1 , 1 , 1 , -1 , -1};
    int yd[8] = {1 , -1 , 0 , 0 , 1 , -1 , 1 , -1};
    bool valid(int i , int j , int n){
        return i >= 0 && i < n && j >= 0 && j < n;
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>>d(n , vector<int>(n));
        if(grid[0][0] || grid[n - 1][n - 1])
            return -1;
        for(int i = 0 ; i < n ; i++){
            for(int j=  0 ; j < n ; j++){
                d[i][j] = 100000;
            }
        }
        d[0][0] = 0;
        queue<array<int,2>>q;
        q.push({0 , 0});
        while(!q.empty()){
            array<int,2>curr = q.front();
            q.pop();
            for(int k = 0 ; k < 8 ; k++){
                int n_i = curr[0] + xd[k];
                int n_j = curr[1] + yd[k];
                if(valid(n_i , n_j , n) && grid[n_i][n_j] == 0 && d[n_i][n_j] > d[curr[0]][curr[1]] + 1){
                    d[n_i][n_j] = d[curr[0]][curr[1]] + 1;
                    q.push({n_i , n_j});
                }
            }
        }
        return d[n - 1][n - 1] < 100000 ? d[n - 1][n - 1] + 1 : -1;
    }
};