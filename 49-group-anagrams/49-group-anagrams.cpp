class Solution {
public:
    vector<vector<string>>ret;
    vector<string>vs;
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        for(auto it : strs){
            string s = it;
            sort(s.begin() , s.end());
            bool flag = false;
            for(int i = 0 ; i < (int)ret.size() ; i++){
                if(s == vs[i]){
                    flag = true;
                    ret[i].push_back(it);
                    break;
                }
            }
            if(!flag){
                vs.push_back(s);
                vector<string>p = {it};
                ret.push_back(p);
            }
        }
        return ret;
    }
};