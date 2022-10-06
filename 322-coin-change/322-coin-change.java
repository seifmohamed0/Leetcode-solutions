class Solution {
    public int coinChange(int[] coins, int amount) {
        int[] mem = new int[amount + 1];
        Arrays.fill(mem , amount + 1);
        mem[0] = 0;
        for(int i = 1 ; i <= amount ; i++){
            for(int coin : coins){
                if(i - coin >= 0){
                    mem[i] = Math.min(mem[i] , mem[i - coin] + 1);
                }
            }
        }
        return mem[amount] == amount + 1 ? -1 : mem[amount];
    }
}