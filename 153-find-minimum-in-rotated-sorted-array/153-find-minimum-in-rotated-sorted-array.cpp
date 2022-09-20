class Solution {
public:
    int findMin(vector<int>& nums) {
        int mid_point = -1;
        int n = nums.size();
        int l = 0 , r = nums.size() - 1 , mid;
        while(r >= l){
            mid = (l + r) / 2;
            if(nums[mid] > nums[n - 1]){
                mid_point = mid;
                l = mid + 1;
            }else {
                r = mid - 1;
            }
        }
        if(mid_point == -1)
            return nums[0];
        else return nums[mid_point + 1];
    }
};