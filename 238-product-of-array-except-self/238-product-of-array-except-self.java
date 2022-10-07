class Solution {
    public int[] productExceptSelf(int[] nums) {
        int n = nums.length;
        int[] ret = new int[n];
        int mul = 1;
        int zeros=  0;
        for(int i = 0; i < n ; i++){
            if(nums[i] == 0)
                ++zeros;
            else mul = mul * nums[i];
        }
        if(zeros > 1)return ret;
        for(int i = 0 ; i < n ; i++){
            if(zeros == 1 && nums[i] != 0){
                ret[i] = 0;
            }else if(zeros == 1 && nums[i] == 0){
                ret[i] = mul;
            }else ret[i] = mul / nums[i];
        }
        return ret;
    }
}