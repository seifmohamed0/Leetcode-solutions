class Solution {
    public boolean valid(int mid , int[] nums , int maxOperations){
        for(int i = 0 ; i < nums.length ; i++){
            if(nums[i] > mid){
                maxOperations -= ((nums[i] - mid) + ( mid - 1))/ mid;
                if(maxOperations < 0)
                    return false;
            }
        }
        return true;
    }
    public int minimumSize(int[] nums, int maxOperations) {
        int l = 1 , r = 1000000000 , ret = 1000000000 , mid;
        while(r >= l){
            mid = (l + r) / 2;
            if(valid(mid , nums , maxOperations)){
                r = mid - 1;
                ret = mid;
            }else {
                l = mid + 1;
            }
        }
        return ret;
    }
}