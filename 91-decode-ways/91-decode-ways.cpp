class Solution {
public:
    int numDecodings(string s) {
        vector<int> dp(s.size(),1);
        if(s[0]=='0')
            return 0;
        if(s.size()>1&&stoi(string(1,s[0])+s[1]) <=26&&s[1]!='0')
            dp[1] = dp[0] + 1;
        if(s.size()>1 && s[1]=='0'&& (s[0]=='0'||s[0] > '2'))
            return 0;
        for(int i = 2 ; i < s.size() ; ++i){
            if(s[i]=='0' && (s[i-1]=='0'||s[i-1] > '2'))
                return 0;
            if(stoi(string(1,s[i-1])+s[i]) <=26&&s[i]!='0'&&stoi(string(1,s[i-1])+s[i])>10)
                dp[i] = dp[i-1] +dp[i-2];
            else if(s[i]=='0')
                dp[i] = dp[i-2];
            else
                dp[i] = dp[i-1];
        }
        return dp[dp.size()-1];
    }
};