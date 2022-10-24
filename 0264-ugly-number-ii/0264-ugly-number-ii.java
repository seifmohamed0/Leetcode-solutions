public class Solution {
    public int nthUglyNumber(int n) {
        int[] mem = new int[n];
        mem[0] = 1;
        int f2 = 0, f3 = 0, f5 = 0;
        int fac2 = 2, fac3 = 3, fac5 = 5;
        for(int i =1 ;i < n; i++){
            int min = Math.min(Math.min(fac2,fac3),fac5);
            mem[i] = min;
            if(fac2 == min)
                fac2 = 2*mem[++f2];
            if(fac3 == min)
                fac3 = 3*mem[++f3];
            if(fac5 == min)
                fac5 = 5*mem[++f5];
        }
        return mem[n-1];
    }
}