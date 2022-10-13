class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int out = -1e9 , sum = 0;
        for(auto it : nums){
            sum += it;
            out = max(out , sum);
            if(sum < 0)
                sum = 0;
        }
        return out;
    }
};