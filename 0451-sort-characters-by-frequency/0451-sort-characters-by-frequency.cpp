class Solution {
public:
    string frequencySort(string s) {
        vector<int>frq(128);
        for(auto it : s)
            frq[it]++;
        vector<array<int,2>>ret;
        for(int i = 0 ; i < 128 ; i++){
            if(frq[i]){
                ret.push_back({frq[i] , i});
            }
        }
        sort(ret.rbegin() , ret.rend());
        string sret = "";
        for(auto &it : ret){
            while(it[0]--)
                sret += (char)it[1];
        }
        return sret;
    }
};