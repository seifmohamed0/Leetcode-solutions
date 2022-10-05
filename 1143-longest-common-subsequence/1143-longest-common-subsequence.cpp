class Solution {
public:
    int n , m , dp[1005][1005];
    int solve(int idx1 , int idx2 , string& t1 , string& t2){
        if(idx1 == n || idx2 == m)
            return 0;
        if(dp[idx1][idx2] != -1)
            return dp[idx1][idx2];
        
        int ret = 0;
        if(t1[idx1] == t2[idx2])
            ret = solve(idx1 + 1 , idx2 + 1 , t1 , t2) + 1;
        ret = max(ret , solve(idx1 + 1 , idx2 , t1 , t2));
        ret = max(ret , solve(idx1 , idx2+1 , t1 , t2));
        return dp[idx1][idx2] = ret;
    }
    int longestCommonSubsequence(string text1, string text2) {
         n = text1.size();
        m = text2.size();
        memset(dp , -1 , sizeof(dp));
        return solve(0 , 0 , text1 , text2);
    }
};