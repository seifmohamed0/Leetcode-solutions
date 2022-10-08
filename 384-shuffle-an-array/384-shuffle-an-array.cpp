class Solution {
public:
    vector<int>nums2;
    vector<int>Nums;
    int cnt = 0;
    Solution(vector<int>& nums) {
        for(auto it : nums){
            nums2.push_back(it);
            Nums.push_back(it);   
        }
    }
    
    vector<int> reset() {
        return nums2;
    }
    
    vector<int> shuffle() {
        vector<int>v2 = Nums;
        next_permutation(Nums.begin() , Nums.end());
        if(v2 == Nums){
            sort(Nums.begin() , Nums.end());
        }
        return Nums;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */