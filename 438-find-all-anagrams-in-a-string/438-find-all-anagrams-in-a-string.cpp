class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int>frq(26) , frq2(26);
        for(auto it : p)
            frq[it - 97]++;
        int sum = p.size();
        vector<int>ret;
        int m = p.size() , n = s.size();
        for(int i = n - 1 ; i >= 0; i--){
            int x = s[i] - 97;
            sum -= abs(frq[x] - frq2[x]);
            frq2[x]++;
            sum += abs(frq[x] - frq2[x]);
            if(n - i > m){
                int rx = s[i + m] - 97;
                sum -= abs(frq[rx] - frq2[rx]);
                frq2[rx]--;
                sum += abs(frq[rx] - frq2[rx]);
            }
            if(!sum)ret.push_back(i);
        }
        return ret;
    }
};