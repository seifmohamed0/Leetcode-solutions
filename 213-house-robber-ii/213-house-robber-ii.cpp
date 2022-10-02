class Solution {
public:
    int n ;
    int dp[105][2];
    int solve(int idx , bool state , vector<int>&nums){
        if(idx >= n)
            return 0;
        if(dp[idx][state] != -1)
            return dp[idx][state];
        if(idx == 0){
            return dp[idx][state] = max(solve(idx + 1 , 0 , nums) 
                                        , solve(idx + 2 , 1 , nums) + nums[idx]);
        }
        if(idx == n - 1){
            if(!state){
                return dp[idx][state] = nums[idx];
            }else{
                return dp[idx][state] = 0;
            }
        }
        return dp[idx][state] = max(solve(idx + 1 , state , nums)
                                    , solve(idx + 2 , state , nums) + nums[idx]);
    }
    int rob(vector<int>& nums) {
        n = nums.size();
        memset(dp , -1  , sizeof(dp));
        return solve(0 , 0 , nums);
    }
};