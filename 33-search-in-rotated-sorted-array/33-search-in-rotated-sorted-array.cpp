class Solution {
public:
    int search(vector<int>& nums, int target) {
        int mid_point = -1;
        int n = nums.size();
        int l = 0 , r = n - 1 , mid;
        while(r >= l){
            mid = (l + r) / 2 ;
            if(nums[mid] > nums[n - 1]){
                mid_point = mid;
                l = mid + 1;
            }else{
                r = mid - 1;
            }
        }
        if(mid_point != -1){
            l = 0 , r = mid_point;
            while(r >= l){
                mid = (l + r) / 2;
                if(nums[mid] == target)
                    return mid;
                if(nums[mid] > target){
                    r = mid - 1;
                }else {
                    l = mid + 1;
                }
            }
        }
        l = mid_point + 1 , r = n - 1;
        while(r >= l){
                mid = (l + r) / 2;
                if(nums[mid] == target)
                    return mid;
                if(nums[mid] > target){
                    r = mid - 1;
                }else {
                    l = mid + 1;
                }
        }
        return -1;
    }
};