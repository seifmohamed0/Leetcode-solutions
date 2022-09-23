class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k <= 1)
            return 0;
        int ret = 0;
        int ptr1 = 0 , ptr2 = 0 , sum = 1;
        int n = nums.size();
        while(ptr2 < n){
            sum *= nums[ptr2++];
            while(ptr1 < n && sum >= k){
                sum /= nums[ptr1++];
            }
            ret += ptr2 - ptr1;
        }
        return ret;
    }
};