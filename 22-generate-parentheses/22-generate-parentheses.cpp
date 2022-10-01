class Solution {
public:
    vector<string>ret;
    string curr = "";
    void solve(int n ,int open , int close){
        if(close == n)
            return void(ret.push_back(curr));
        if(open < n){
            curr += '(';
            solve(n , open + 1 , close);
            curr.pop_back();
        }
        if(close < open){
            curr += ')';
            solve(n , open , close + 1);
            curr.pop_back();
        }
        return;
    }
    vector<string> generateParenthesis(int n) {
        solve(n , 0 , 0);    
        return ret;
    }
};