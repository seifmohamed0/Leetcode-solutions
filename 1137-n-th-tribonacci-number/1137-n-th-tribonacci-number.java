class Solution {
    public int tribonacci(int n) {
        if(n <= 1)
            return n;
        if(n <= 3)
            return n - 1;
        int ll_prv = 0 , l_prv = 1 , prv = 1;
        int ret = 0;
        int ptr = 3;
        while(ptr <= n){
            ret = ll_prv + l_prv + prv;
            ++ptr;
            ll_prv = l_prv;
            l_prv = prv;
            prv = ret;
        }
        return ret;
    }
}