class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        map<int,int>mp;
        map<array<int,2> , bool>ex;
        vector<vector<int>>ret;
        for(auto it : nums){
            mp[it]++;
        }
        int n = nums.size();
        for(int i = 0; i < n ; i++){
            mp[nums[i]]--;
            for(int j = i + 1; j < n ; j++){
                if(j > i + 1 && nums[j] == nums[j - 1])continue;
                mp[nums[j]]--;
                int sum = 0 - (nums[i] + nums[j]);
                if(mp.find(sum) != mp.end() && mp[sum] > 0){
                    vector<int>v = {nums[i] , nums[j] , sum};
                    sort(v.begin() , v.end());
                    if(ex.find({v[0] , v[1]}) == ex.end()){
                        ret.push_back(v);
                        ex[{v[0] , v[1]}] = true;
                    }
                }
                mp[nums[j]]++;
            }
            mp[nums[i]]++;
        }
        return ret;
    }
};