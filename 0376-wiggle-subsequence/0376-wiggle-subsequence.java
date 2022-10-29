class Solution {
    public int wiggleMaxLength(int[] nums) {
        int ret1 = 1 , ret2 = 1;
        int prv = nums[0];
        boolean g = true;
        for(int i = 1 ; i < nums.length ; i++){
            if(g == true && nums[i] > prv){
                ++ret1;
                g = false;
                prv = nums[i];
            }else if(g == false && nums[i] < prv){
                ++ret1;
                g = true;
                prv = nums[i];
            }else{
                prv = nums[i];
            }
        }
        prv = nums[0];
         g = false;
        for(int i = 1 ; i < nums.length ; i++){
            if(g == true && nums[i] > prv){
                ++ret2;
                g = false;
                prv = nums[i];
            }else if(g == false && nums[i] < prv){
                ++ret2;
                g = true;
                prv = nums[i];
            }else{
                prv = nums[i];
            }
        }
        return Math.max(ret1 , ret2);
    }
}