class Solution {
public:
    int dp[50004][2];
    int n , fe;
    int a[50004];
    int solve(int idx , int state){
        if(idx == n)
            return 0;
        if(dp[idx][state] != -1)
            return dp[idx][state];
        int ret = 0;
        if(!state){
            ret = max(solve(idx + 1 , 0) , solve(idx +  1 , 1) - a[idx] - fe);
        }else{
            ret = max(solve(idx + 1 , 1) , solve(idx , 0) + a[idx]);
        }
        return dp[idx][state] = ret;
    }
    int maxProfit(vector<int>& prices, int fee) {
        n = prices.size() , fe = fee;
        for(int i = 0 ; i < n ; i++){
            a[i] = prices[i];
            dp[i][0] = dp[i][1] = -1;
        }
        return solve(0 , 0);
    }
};