class Solution {
    public int findTheWinner(int n, int k) {
        int ret = 0;
        for(int i = 1 ; i <= n ; i++){
            ret = (ret + k) % i;
        }   
        return ret + 1;
    }
}