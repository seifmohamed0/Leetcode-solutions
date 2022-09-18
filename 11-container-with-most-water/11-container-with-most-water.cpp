class Solution {
public:
    int sg[400005];
    void build(int node , int nl ,int nr ,vector<int>&h){
        if(nl == nr){
            return void(sg[node] = h[nl]);
        }
        int mid = (nl +nr) / 2;
        build(node * 2 , nl , mid , h);
        build(node * 2 + 1 , mid + 1 , nr , h);
        return void(sg[node] = max(sg[node * 2] , sg[node * 2 + 1]));
    }
    int qry_left(int node , int nl , int nr, int h){
        if(nl == nr){
            return nl;
        }
        int mid = (nl + nr) / 2;
        if(sg[node * 2] >= h){
            return qry_left(node * 2 , nl , mid , h);
        }else {
            return qry_left(node * 2 + 1 , mid + 1 , nr , h);
        }
    }
    int qry_right(int node , int nl , int nr, int h){
        if(nl == nr){
            return nl;
        }
        int mid = (nl + nr) / 2;
        if(sg[node * 2 + 1] >= h){
            return qry_right(node * 2 + 1 , mid + 1 , nr , h);
        }else {
            return qry_right(node * 2 , nl , mid , h);
        }
    }
    int maxArea(vector<int>& height) {
        int n = height.size();
        build(1 , 0 , n - 1 , height);
        int ans = 0;
        for(int i = 0 ; i < n ; i++){
            int l = qry_left(1 , 0 , n - 1 , height[i]);
            int r = qry_right(1 , 0 , n - 1 , height[i]);
            if(l != i){
                ans = max(ans , (i - l) * height[i]);
            }
            if(r != i){
                ans = max(ans , (r - i) * height[i]);
            }
        }
        return ans;
    }
};