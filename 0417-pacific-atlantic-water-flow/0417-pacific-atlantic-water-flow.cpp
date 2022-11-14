class Solution {
public:
    int n , m;
    int xd[4] = {0 , 0 , 1 , -1};
    int yd[4] = {1 , -1 , 0 , 0};
    bool valid(int x , int y){
        return x >= 0 && x < n && y >=0 && y < m;
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        n = heights.size();
        m = heights[0].size();
        vector<vector<int>>box(n , vector<int>(m));
        queue<array<int,2>>q;
        
        for(int i = 0 ; i < n ; i++){
            q.push({i , m - 1});
            box[i][m - 1] = 1;
        }
        for(int i = 0 ; i < m - 1 ; i++){
            q.push({n - 1 , i});
            box[n - 1][i] = 1;
        }
        
        while(!q.empty()){
            array<int,2>node = q.front();
            q.pop();
            for(int k = 0 ; k < 4 ; k++){
                array<int,2>new_node = {node[0] + xd[k] , node[1] + yd[k]};
                if(valid(new_node[0] , new_node[1]) && !box[new_node[0]][new_node[1]] &&
                   heights[new_node[0]][new_node[1]] >= heights[node[0]][node[1]]){
                    box[new_node[0]][new_node[1]] = 1;
                    q.push({new_node[0] , new_node[1]});
                }
            }
        }
        
        for(int i = 0 ; i < n ; i++){
            box[i][0] += 2;
            q.push({i , 0});
        }
        for(int j = 0 ; j < m ; j++){
            if(box[0][j] < 2){
                box[0][j] += 2;
                q.push({0 , j});
            }
        }
        
        while(!q.empty()){
            array<int,2>node = q.front();
            q.pop();
            for(int k = 0 ; k < 4 ; k++){
                array<int,2>new_node = {node[0] + xd[k] , node[1] + yd[k]};
                 if(valid(new_node[0] , new_node[1]) && box[new_node[0]][new_node[1]] <= 1 &&
                   heights[new_node[0]][new_node[1]] >= heights[node[0]][node[1]]){
                    box[new_node[0]][new_node[1]] += 2;
                    q.push({new_node[0] , new_node[1]});
                }
            }
        }
        
        vector<vector<int>>ret;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m; j++){
                if(box[i][j] == 3){
                    vector<int>v = {i , j};
                    ret.push_back(v);
                }
            }
        }
        return ret;
    }
};