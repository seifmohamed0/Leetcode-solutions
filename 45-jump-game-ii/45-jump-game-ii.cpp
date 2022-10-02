class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n);
        for(int i = 1; i < n ; i++){
            dp[i] = 1e9;
        }
        for(int i = 0; i < n ; i++){
            for(int j = i + 1 ; j <= min(i + nums[i] , n - 1 ) ; j++){
                dp[j] = min(dp[j] , dp[i] + 1);
            }
        }
        return dp[n - 1];
    }
};