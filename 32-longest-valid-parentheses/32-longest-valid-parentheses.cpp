class Solution {
public:
    int longestValidParentheses(string s) {
       stack<int> st;
       int ret = 0 ,cnt = 0;
       st.push(-1);
        for(int i = 0 ; i < s.size(); i++){
        if(s[i] == ')'){
            st.pop();
            if(st.empty())
                st.push(i);
            else
                cnt= i - st.top();
        }
        else 
            st.push(i);
        ret = max(ret , cnt);
        }
        return ret;
    }
};