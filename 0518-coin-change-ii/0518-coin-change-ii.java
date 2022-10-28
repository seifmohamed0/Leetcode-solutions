class Solution {
    public int change(int amount, int[] coins) {
        int[] mem = new int[amount + 1];
        mem[0] = 1;
        int n = coins.length;
        for(int i = 0; i < n ; i++){
            for(int j = 0; j + coins[i] <= amount ; j++){
                mem[j + coins[i]] += mem[j];
            }
        }
        return mem[amount];
    }
}