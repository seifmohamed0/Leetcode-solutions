class Solution {
    public int combinationSum4(int[] nums, int target) {
        int[] mem = new int [target + 1];
        mem[0] = 1;
        for(int i = 0 ; i <= target ; i++){
            for(int j = 0 ; j < nums.length ; j++){
                if(nums[j] + i <= target){
                    mem[nums[j] + i] += mem[i];
                }
            }
        }
        return mem[target];
    }
}