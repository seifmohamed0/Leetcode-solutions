class Solution {
public:
    int nextGreaterElement(int n) {
        vector<int>v;
        int tmp = n ;
        while(tmp){
            v.push_back(tmp%10);
            tmp /= 10;
        }
        sort(v.begin() , v.end());
        long long ret = -1;
        do{
            long long num = 0;
            for(auto it : v){
                num *= 10;
                num += it;
            }
            if(num > n && num < (1ll << 31)){
                ret = ret == -1 ? num : min(num,ret);
            }
        }while(next_permutation(v.begin() , v.end()));
        return ret;
    }
};