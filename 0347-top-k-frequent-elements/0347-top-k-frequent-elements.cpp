class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int>frq(20050);
        for(auto it: nums){
            frq[it + 10001]++;
        }
        priority_queue<array<int,2>>pq;
        for(int i = 0 ; i < 20050 ; i++){
            if(frq[i])
                pq.push({frq[i] , i - 10001});
        }
        vector<int>ret;
        while(k--){
            ret.push_back(pq.top()[1]);
            pq.pop();
        }
        return ret;
    }
};