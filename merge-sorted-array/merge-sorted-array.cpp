class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int>ret;
        int ptr1 = 0 , ptr2 = 0;
        while(ptr1 < m || ptr2 < n){
            if(ptr1 == m)
                ret.push_back(nums2[ptr2++]);
            else if(ptr2 == n)
                ret.push_back(nums1[ptr1++]);
            else if(nums1[ptr1] <= nums2[ptr2])
                ret.push_back(nums1[ptr1++]);
            else ret.push_back(nums2[ptr2++]);
        }
        nums1 = ret;
    }
};