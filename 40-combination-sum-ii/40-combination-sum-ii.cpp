class Solution {
public:
    vector<vector<int>>ret;
    vector<int>vi;
    int n ;
    void solve(int i , vector<int>&v , int rem){
        if(rem == 0){
            return void(ret.push_back(vi));
        }
        if(i >= n)
            return ;
        
        for(int idx = i; idx < n; idx++){
            if(v[idx]<=rem)
            {
                if(idx>i && v[idx]==v[idx-1]) 
                    continue;
                vi.push_back(v[idx]);
                solve(idx+1,v,rem-v[idx]);
                vi.pop_back();
            }
        }
        return ;
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        n = candidates.size();
        sort(candidates.begin() , candidates.end());
        solve(0 , candidates , target);
        return ret;
    }
};