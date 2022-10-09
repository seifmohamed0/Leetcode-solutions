class Solution {
    public boolean isHappy(int n) {
        int rep = 50;
        long prv = n;
        while(rep > 0){
            --rep;
            long curr = 0;
            while(prv > 0){
                int p = (int)(prv % 10);
                prv /= 10;
                curr += p * p;
            }
            if(curr == 1)
                return true;
            prv = curr;
        }
        return false;
    }
}