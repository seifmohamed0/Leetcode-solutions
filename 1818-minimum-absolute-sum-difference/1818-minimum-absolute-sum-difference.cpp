class Solution {
public:
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        long ret = 0, mx = 0;
        set<int> st;
        for(auto it : nums1){
            st.insert(it);
        }
        for (int i = 0; i < nums1.size(); ++i) {
            long curr = abs(nums1[i] - nums2[i]);
            ret += curr;
            if (mx < curr) {
                auto it = st.lower_bound(nums2[i]);
                if (it != st.end())
                    mx = max(mx, curr - abs(*it - nums2[i]));
                if (it != st.begin()){
                    --it;
                    mx = max(mx, curr - abs(*it - nums2[i]));
                }
            }
        }
        return (ret - mx) % 1000000007;        
    }
};