class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<array<int,3>>pq;
        for(auto it : points){
            int dist = it[0]*it[0] + it[1]*it[1];
            pq.push({-dist , it[0] , it[1]});
        }        
        vector<vector<int>>ret;
        while(k--){
            array<int,3>curr = pq.top();
            pq.pop();
            vector<int>v = {curr[1] , curr[2]};
            ret.push_back(v);
        }
        return ret;
    }
};