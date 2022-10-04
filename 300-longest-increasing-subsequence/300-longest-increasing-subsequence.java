class Solution {
    public int lengthOfLIS(int[] nums) {
        int[] arr = new int[nums.length];
        arr[0] = nums[0];
        int ret = 1;
        for(int it : nums){
            if(it > arr[ret - 1]){
                arr[ret++] = it; 
                continue;
            }
            int l = 0 , r = ret - 1 , mid = 0;
            while(l != r){
                mid = (l + r) / 2;
                if(it <= arr[mid]){
                    r = mid;
                }else{
                    l = mid + 1;
                }
            }
            arr[l] = it;
            if(ret == l){
                ++ret;
            }
        }
        return ret;
    }
}