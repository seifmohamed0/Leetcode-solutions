class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        //idx
        stack<int>st;
        vector<int>l(n) , r(n);
        for(int i = n - 1 ; i >= 0 ; i--){
            while(!st.empty() && heights[i] < heights[st.top()]){
                l[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        while(!st.empty()){
            l[st.top()] = -1;
            st.pop();
        }
        for(int i = 0 ; i < n ; i++){
            while(!st.empty() && heights[i] < heights[st.top()]){
                r[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        while(!st.empty()){
            r[st.top()] = n;
            st.pop();
        }
        long long ans = 0;
        for(int i = 0 ; i < n ; i++){
            ans = max(ans , (long long)(r[i] - l[i] - 1) * heights[i]);
        }
        return ans;
    }
};