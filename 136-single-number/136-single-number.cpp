class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<bool>v(60005);
        for(auto it : nums){
            v[it + 30000] = v[it + 30000] ^ 1;
        }
        for(int i = 0 ; i < 60005 ; i++){
            if(v[i] > 0)
                return i - 30000;
        }
        return 0;
    }
};