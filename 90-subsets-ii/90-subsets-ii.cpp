class Solution {
public:
    int n;
    multiset<int>ms;
    set<multiset<int>>ret;
    void solve(int idx , vector<int>& nums){
        if(idx == n){
            return void(ret.insert(ms));
        }
        solve(idx + 1 , nums);
        ms.insert(nums[idx]);
        solve(idx + 1 , nums);
        ms.erase(ms.find(nums[idx]));
        return ;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        n = nums.size();
        solve(0 , nums);
        vector<vector<int>>reet;
        for(auto it : ret){
            vector<int>vec;
            for(auto it2 : it){
                vec.push_back(it2);
            }
            reet.push_back(vec);
        }
        return reet;
    }
};