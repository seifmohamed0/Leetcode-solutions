class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        if(!n) 
            return 0;
        int l =0 , r = n - 1;
        int ret = 0 , mid;
        while(l <= r){
            mid  = l + (r - l) / 2;
            if(citations[mid] >= n - mid){
                ret = n - mid;
                r = mid - 1;
            }else{
                l  = mid + 1;
            }
        }
        
        return ret;        
    }
};