class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int sz = 2;
        long long ans = 0;
        int n = nums.size();
        if(n == 1)return 0;
        int diff = nums[1] - nums[0];
        for(int i = 2 ; i < n ; i++){
            if(nums[i] - nums[i - 1] != diff){
                // compute answer
                if(sz >= 3){
                    sz -= 2;
                    ans += sz * (sz + 1) / 2;
                }               
                // init
                sz = 2;
                diff = nums[i] - nums[i - 1];
            }else{
                ++sz;
            }
        }
        sz -= 2;
        if(sz > 0)ans += sz*(sz + 1) / 2;
        return ans;
    }
};