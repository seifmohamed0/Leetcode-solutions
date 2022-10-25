class Solution {
    String s ;
    int[][] dp;
    int n;
    public int solve(int l , int r){
        if(l > r)
            return 0;
        if(l == r)
            return 1;
        if(dp[l][r] != -1)
            return dp[l][r];
        int ret = 0;
        ret = solve(l + 1 , r - 1) + (s.charAt(l) == s.charAt(r) ? 2 : 0);
        ret = Math.max(ret , solve(l + 1 , r));
        ret = Math.max(ret , solve(l , r - 1));
        return dp[l][r] = ret;
    }
    public int longestPalindromeSubseq(String s) {
        this.s = s;
        n = s.length();
        dp = new int[n][n];
        for(int i = 0 ; i < n ; i++)
            Arrays.fill(dp[i] , -1);
        return solve(0 , n - 1);
    }
}