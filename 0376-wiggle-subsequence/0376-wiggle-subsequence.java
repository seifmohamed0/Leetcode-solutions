class Solution {
    public int wiggleMaxLength(int[] nums) {
        int ret1 = 1 , ret2 = 1;
        boolean g = true;
        for(int i = 1 ; i < nums.length ; i++){
            if(g == true && nums[i] > nums[i - 1]){
                ++ret1;
                g = false;
            }else if(g == false && nums[i] < nums[i - 1]){
                ++ret1;
                g = true;
            }
        }
        g = false;
        for(int i = 1 ; i < nums.length ; i++){
            if(g == true && nums[i] > nums[i - 1]){
                ++ret2;
                g = false;
            }else if(g == false && nums[i] < nums[i - 1]){
                ++ret2;
                g = true;
            }
        }
        return Math.max(ret1 , ret2);
    }
}