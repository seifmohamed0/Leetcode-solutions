class Solution {
public:
    vector<vector<int>>ret;
    int n ;
    vector<int>v;
    void solve(int indx , int rem , vector<int>&c){
        if(rem == 0)
            return void(ret.push_back(v));
        if(indx == n)
            return;
        if(rem - c[indx] >= 0){
            v.push_back(c[indx]);
            solve(indx , rem - c[indx] , c);
            v.pop_back();
        }
        solve(indx + 1, rem, c);
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        n = candidates.size();
        solve(0 , target , candidates);    
        return ret;
    }
};