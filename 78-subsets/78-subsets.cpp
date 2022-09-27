class Solution {
public:
    int n ;
    vector<vector<int>>ret;
    void solve(int idx , vector<int>&nums , vector<int>v ){
        if(idx == n)
            return void(ret.push_back(v));
        solve(idx + 1, nums , v);
        v.push_back(nums[idx]);
        solve(idx + 1 , nums , v);
        v.pop_back();
        return;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        n = nums.size();
        vector<int>v;
        solve(0 , nums , v);
        return ret;
    }
};