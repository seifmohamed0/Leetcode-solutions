class Solution {
public:
    bool vis[2][6002];
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        int mx = 6002;
        vector<bool>is_forb(mx);
        for(auto it : forbidden)
            is_forb[it] = true;
        if(is_forb[0])
            return -1;
        if(x == 0)
            return 0;
        queue<array<int,3>>q;
        q.push({0 , 1 , 0});
        vis[1][0] = true;
        while(!q.empty()){
            array<int,3>curr = q.front();
            q.pop();
            if(a + curr[0] <= mx - 1){
                if(!vis[1][a + curr[0]] && !is_forb[a + curr[0]]){
                    vis[1][a + curr[0]] = true;
                    q.push({a + curr[0] , 1 , curr[2] + 1});
                    if(a + curr[0] == x){
                        return curr[2] + 1;
                    }
                }
            }
            if(curr[1] == 1 && curr[0] - b >= 0 && !vis[0][curr[0] - b] &&                           !is_forb[curr[0] - b]){
                vis[0][curr[0] - b] = true;
                q.push({curr[0] - b , 0 , curr[2] + 1});
                if(curr[0] - b == x){
                    return curr[2] + 1;
                }
            }
        }
        return -1;
    }
};