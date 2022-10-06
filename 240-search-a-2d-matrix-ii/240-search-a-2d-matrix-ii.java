class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        for(int l = 0 ; l < matrix.length ; l++){
        if(matrix[l][0] > target)break;
        if(matrix[l][matrix[0].length - 1] < target)continue;
         int l2 = 0 , r2 = matrix[0].length - 1 , mid;
         while(r2 >= l2){
             mid = (l2 + r2) / 2;
             if(matrix[l][mid] == target)
                 return true;
             if(matrix[l][mid] > target){
                 r2 = mid - 1 ;
             }else{
                  l2 = mid + 1;
             }
            }
        }
        return false;
    }
}