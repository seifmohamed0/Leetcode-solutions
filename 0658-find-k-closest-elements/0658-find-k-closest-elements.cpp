class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int l = upper_bound(arr.begin() , arr.end() , x) - arr.begin();
        if(l)
            --l;
        int n = arr.size();
        if(l + 1 < n && x - arr[l] > arr[l + 1] - x){
            ++l;
        }
        int r = l;
        --k;
        while(k--){
            int l_diff = 1e9 , r_diff = 1e9;
            if(l - 1 >= 0)
                l_diff = x - arr[l - 1];
            if(r + 1 < n)
                r_diff = arr[r + 1] - x;
            if(l_diff <= r_diff){
                --l;
            }else{
                ++r;
            }
        }
        vector<int>ret;
        for(int i = l ;i <= r ; i++)
            ret.push_back(arr[i]);
        return ret;
    }
};