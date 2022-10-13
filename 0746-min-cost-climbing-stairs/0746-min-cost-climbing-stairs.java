class Solution {
    public int minCostClimbingStairs(int[] cost) {
        int n = cost.length;
        int[] dp = new int[n];
        if(n == 1)
            return cost[0];
        for(int i = 2 ; i < n ; i++){
            dp[i] = Math.min(dp[i - 1] + cost[i - 1] , dp[i - 2] + cost[i - 2]);
        }
        return Math.min(dp[n - 1] + cost[n - 1] , dp[n - 2] + cost[n - 2]);
    }
}