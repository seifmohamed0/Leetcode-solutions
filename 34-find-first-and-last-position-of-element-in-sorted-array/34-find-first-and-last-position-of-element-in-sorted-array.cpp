class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>ret = {-1 , -1};
        int idx = lower_bound(nums.begin() , nums.end() , target) - nums.begin();
        int n = nums.size();
        if(idx != n && nums[idx] == target){
            ret[0] = ret[1] = idx;
        }
        idx = upper_bound(nums.begin() , nums.end() , target) - nums.begin();
        --idx;
        if(idx >= 0 && nums[idx] == target)
            ret[1] = idx;
        return ret;
    }
};