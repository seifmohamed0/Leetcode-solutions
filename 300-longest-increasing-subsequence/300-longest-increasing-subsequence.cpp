class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>v;
        int n = nums.size();
        int ret = 1;
        v.push_back(nums[0]);
        for(int i = 1 ; i < n ; i++){
            if(nums[i] > v.back()){
                ++ret;
                v.push_back(nums[i]);
            }else{
                v[lower_bound(v.begin() , v.end() , nums[i]) - v.begin()] = nums[i];
            }
        }
        return ret;
    }
};