class Solution {
    public int findNumberOfLIS(int[] nums) {
        int[] dp = new int[nums.length];
        int[] cnt = new int[nums.length];
        int mx = 0;
        for(int i = 0 ; i < nums.length ; i++){
            dp[i] = 1;
            cnt[i] = 1;
            int curr_cnt = 0;
            for(int j = i - 1 ; j >= 0 ; j--){
                if(nums[i] > nums[j] && dp[j] + 1 > dp[i]){
                    dp[i] = dp[j] + 1;
                    cnt[i] = cnt[j]; 
                }
                else if(nums[i] > nums[j] && dp[j] + 1 == dp[i])
                    cnt[i] += cnt[j];
            }
            if(dp[i] > mx){
                mx = dp[i] ;
            }
        }
        int ret = 0;
        for(int i = 0 ; i < cnt.length ; i++){
            ret += dp[i] == mx ? cnt[i] : 0;
        }
        return ret;
    }
}