class Solution {
public:
    int n , m;
    int xd[4] = {0 , 0 , 1 , -1};
    int yd[4] = {1 , -1 , 0 , 0};
    bool valid(int x , int y){
        return x >= 0 && x < n && y >= 0 && y < m;
    }
    int solve(int x1 ,int y1 , int x2 ,int y2 , vector<vector<int>>&v){
        if(x1 == x2 && y1 == y2)return 0;
        vector<vector<int>>d(n , vector<int>(m));
        queue<array<int,2>>q;
        q.push({x1 , y1});
        d[x1][y1] = 1;
        while(!q.empty()){
            array<int,2>a = q.front();
            q.pop();
            for(int k = 0 ; k < 4 ; k++){
                int nx = a[0] + xd[k] , ny = a[1] + yd[k];
                if(valid(nx , ny) && v[nx][ny] != 0 && d[nx][ny] == 0){
                    d[nx][ny] = d[a[0]][a[1]] + 1;
                    q.push({nx , ny});
                    if(nx == x2 && ny == y2){
                        return d[a[0]][a[1]];
                    }
                }
            }
        }
        return -1;
    }
    int cutOffTree(vector<vector<int>>& forest) {
        if(forest[0][0] == 0)return -1;
        vector<array<int,3>>v;
        n = forest.size() , m = forest[0].size();
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(forest[i][j] > 1){
                    v.push_back({forest[i][j] , i , j});
                }
            }
        }
        sort(v.begin() , v.end());
        int ans = 0 , x = 0 , y = 0;
        for(auto it : v){
            int p = solve(x , y , it[1] , it[2] ,forest);
            cout<<it[0]<<" "<<it[1]<<" "<<it[2]<<" "<<p<<'\n';
            if(p == -1)return p;
            ans += p;
            x = it[1] , y = it[2];
        }
        return ans;
    }
};