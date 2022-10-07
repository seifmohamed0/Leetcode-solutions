class Solution {
    public int rangeBitwiseAnd(int left, int right) {
        int ret = 0;
        for(int i = 31 ; i >= 0; i--){
            int b1 = (1 << i) & left;
            int b2 = (1 << i) & right;
            if(b1 != 0 && b2 != 0)
                ret += (1 << i);
            else if(b1 > 0 || b2 > 0)
                break;
        }
        return ret;
    }
}