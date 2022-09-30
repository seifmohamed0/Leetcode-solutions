class Solution {
public:
    string s[10] = {
        "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"
    };
    vector<string>ret;
    string curr = "";
    int n ;
    void solve(int idx , string& d){
        if(idx == n){
            if(curr != "")
                 return void(ret.push_back(curr));
            return;   
        }
        int i = d[idx] - '0';
        for(int j = 0 ; j <  (int)s[i].size() ; j++){
            curr += s[i][j];
            solve(idx + 1 , d);
            curr.pop_back();
        }
        return;
    }
    vector<string> letterCombinations(string digits) {
        n = digits.size();
        solve(0 , digits);
        return ret;
    }
};