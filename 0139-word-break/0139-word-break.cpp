class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if (s.size() == 0 || wordDict.size() == 0) return false;
        int n = s.size();
        vector<bool> dp(n + 1, false); 
        dp[0] = true; 
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < wordDict.size(); j++) {
                int m = wordDict[j].size();
                if (i >= m &&
                    (s.substr(i - m, m) == wordDict[j])) {
                    if (dp[i - m ]) {
                        dp[i] = dp[i - m];
                        break;
                    }
                }

            }

        }
        return dp[n];
    }
};