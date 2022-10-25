class Solution {
    public boolean isMonotonic(int[] nums) {
        int n = nums.length;
        int j = -1;
        for(int i = 1 ; i < n ; i++){
            if(nums[i] != nums[i - 1]){
                j = i;
                break;
            }
        }
        if(j == -1)
            return true;
        if(nums[j] > nums[j - 1]){
            for(int i = j ; i < n ; i++){
                if(nums[i] < nums[i - 1])
                    return false;
            }
        }else{
            for(int i = j ; i < n ; i++){
                if(nums[i] > nums[i - 1])
                    return false;
            }
        }
        return true;
    }
}