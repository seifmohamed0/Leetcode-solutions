class Solution {
public:
    
    bool valid(string& s , string& p , vector<int>&removable , int k){
        vector<bool>vis(s.size());
        for(int i = 0; i < k ; i++){
            vis[removable[i]] = true;
        }
        int ptr = 0;
        for(int i = 0; i < s.size() && ptr < p.size() ; i++){
            if((!vis[i])){
                ptr += s[i] == p[ptr];
            }
        }
        return ptr == p.size();
    }
    
    int maximumRemovals(string s, string p, vector<int>& removable) {
        int l = 0 , r = removable.size() , mid , ret = -1;
        
        while(r >= l){
            mid = (l + r) / 2;
            if(valid(s , p , removable , mid)){
                ret = mid ;
                l = mid + 1;
            }else{
                r = mid - 1;
            }
        }
        
        return ret;
    }
};