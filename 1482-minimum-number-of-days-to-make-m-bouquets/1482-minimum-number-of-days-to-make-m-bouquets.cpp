class Solution {
public:

    bool valid(vector<int>& bloomDay, int days, int m, int k){
        int cnt = 0 , ret = 0;
        for(int i = 0 ;i < bloomDay.size() ; i++){
            if(bloomDay[i] <= days){
                ++cnt;
            }
            else{
                cnt = 0;
            }
            if(cnt==k){
                cnt=0;
                ret++;
            }
        }
        return ret >= m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int l=1 , r=1e9 , mid , ret = -1;
        while(l <= r){
            mid = l + (r - l)/2;
            if(valid(bloomDay , mid , m , k)){
                ret = mid;
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        return ret; 
    }
};
