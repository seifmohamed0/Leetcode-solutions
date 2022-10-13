class Solution {
    public int rob(int[] nums) {
        int n = nums.length;
        if(n == 1)
            return nums[0];
        int[] dp = new int[n];
        dp[0] = nums[0];
        dp[1] = nums[1];
        for(int i = 2 ; i < n ; i++){
            dp[i] = dp[i - 1];
            dp[i] = Math.max(dp[i - 2] , i >= 3 ? dp[i - 3] : 0) + nums[i];
        }
        return Math.max(dp[n - 1] , dp[n - 2]);
    }
}