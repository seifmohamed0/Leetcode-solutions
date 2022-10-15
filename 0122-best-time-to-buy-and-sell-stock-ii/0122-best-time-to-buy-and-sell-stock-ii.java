class Solution {
    public int maxProfit(int[] prices) {
        int curr = prices[0];
        int ret = 0;
        for(int i = 1 ;i < prices.length ; i++){
            if(curr < prices[i]){
                ret += prices[i] - curr;
            }
            curr = prices[i]; 
        }
        return ret;
    }
}