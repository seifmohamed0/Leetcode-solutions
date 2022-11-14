class Solution {
public:
  int shortestPathLength(vector<vector<int>>& graph) {
    int n = graph.size();
    int ret = 0;
    queue<tuple<int,int,int>> q;
    vector<vector<int>> mem(n,vector<int>(1<<n));
    
    for(int i=0;i<n;i++){
        q.push(tuple<int,int,int>(i,1<<i,0));
        mem[i][1<<i] = true;
    }
    while (!q.empty())
    {
        auto [node,mask,dist] = q.front();
        q.pop();
        if(mask==(1<<n)-1){
            ret = dist;
            break;
        }
        for(auto it:graph[node]){
            int n_mask = mask | (1<<it);
            if(!mem[it][n_mask]){
                q.push(tuple<int,int,int>(it,n_mask,dist+1));
                mem[it][n_mask] = true;
            }
        }
    }
    return ret;
}
};