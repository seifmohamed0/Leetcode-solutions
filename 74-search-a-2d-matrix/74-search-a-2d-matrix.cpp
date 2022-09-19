class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int l = 0 , r = m - 1 , mid = -1 , col = -1;
        if(matrix[m - 1][n - 1] < target)
            return 0;
        while(r >= l){
            mid = (l + r) / 2;
            if(target > matrix[mid][n - 1]){
                l = mid + 1;
            }else{
                col =  mid;
                r = mid - 1;
            }
        }
        l = 0 , r = n - 1;
       while(r >= l){
            mid = (l + r) / 2;
            if(target == matrix[col][mid]){
                return true;
            }else if(target > matrix[col][mid]){
                l = mid + 1;
            }else{
                r = mid - 1;
            }
        }
        return false;
    }
};