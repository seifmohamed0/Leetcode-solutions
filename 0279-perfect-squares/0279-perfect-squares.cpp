class Solution {
public:
    int dp[1000006];
    int solve(int curr){
        if(curr == 0)return 0;
        if(curr < 0)return 1e6;
        if(dp[curr] != 1e9)return dp[curr];
        int ret = curr ;
        for(long long i = 2 ; i * i <= curr ; i++){
            ret = min(ret , solve(curr -(i *i)) + 1);
        }
        return dp[curr] =ret;
    }
    int numSquares(int n) {
        for(int i = 1 ; i <= n ; i++){
            dp[i] = 1e9;
        }
        return solve(n);
    }
};