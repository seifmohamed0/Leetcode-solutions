class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int ptr1 = 0 , ptr2 = 0 , ret = n + 1  , sum = 0;
        while(ptr2 < n){
            sum += nums[ptr2++];
            while(ptr1 < n && sum - nums[ptr1] >= target){
                sum -= nums[ptr1++];
            }
            if(sum >= target)
                ret = min(ret , ptr2 - ptr1);
        }
        return ret == n + 1 ? 0 : ret;
    }
};