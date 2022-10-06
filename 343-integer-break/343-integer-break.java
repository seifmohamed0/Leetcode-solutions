class Solution {
    int[] mem = new int[60];
    int solve(int n){
        if(n <= 3)
            return Math.max(n , 1);
        if(mem[n] != -1)
            return mem[n];
        int ret = n;
        for(int i = 1 ; i < n ; i++){
            ret = Math.max(ret , solve(n - i) * i);
        }
        return mem[n] = ret;
    }
    public int integerBreak(int n) {
        Arrays.fill(mem , -1);
        int ret = 0;
        for(int i = 1 ; i < n ; i++){
            ret = Math.max(ret , solve(n - i) * i);
        }
        return ret;
    }
}