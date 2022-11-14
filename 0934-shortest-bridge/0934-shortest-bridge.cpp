class Solution {
public:
    int n ;
    int xd[4] = {0 , 0 , 1 , -1};
    int yd[4] = {1 , -1 , 0 , 0};
    bool valid(array<int,2>node){
        return node[0] >= 0 && node[0] < n && node[1] >= 0 && node[1] < n; 
    }
    int shortestBridge(vector<vector<int>>& grid) {
        n = grid.size();
        queue<array<int,2>>q , island1;
        vector<vector<bool>>vis(n , vector<bool>(n));
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                if(grid[i][j]){
                    q.push({i , j});
                    island1.push({i , j});
                    vis[i][j] = true;
                    break;
                }
            }
            if(!q.empty())break;
        }
        while(!q.empty()){
            array<int,2>node = q.front();
            q.pop();
            for(int k = 0 ; k < 4 ; k++){
                array<int,2>new_node = {node[0] + xd[k] , node[1] + yd[k]};
                if(valid(new_node) && grid[new_node[0]][new_node[1]] && !vis[new_node[0]][new_node[1]]){
                    q.push(new_node);
                    island1.push(new_node);
                    vis[new_node[0]][new_node[1]] = true;
                }
            }
        }
        for(int i = 1 ;; i++){
            int sz = island1.size();
            while(sz--){
                array<int,2>node = island1.front();
                island1.pop();
                for(int k = 0 ; k < 4 ; k++){
                    array<int,2>new_node = {node[0] + xd[k] , node[1] + yd[k]};
                    if(valid(new_node) && !vis[new_node[0]][new_node[1]]){
                        if(grid[new_node[0]][new_node[1]])
                            return i - 1;
                        vis[new_node[0]][new_node[1]] = true;
                        island1.push(new_node);
                    }
                }
            }
        }
        return 0;
    }
};