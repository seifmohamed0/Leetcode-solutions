class Solution {
    public int maxPoints(int[][] points) {
        if (points.length == 2){
            return 2;
        }
       int ret = 1;
        for (int i = 0; i < points.length - 2; i++){
            int x1 = points[i][0];
            int y1 = points[i][1];
            
            for (int j = i+1; j < points.length-1; j++){
                int cnt = 2;
                int x2 = points[j][0];
                int y2 = points[j][1];
                for (int l = j+1; l < points.length; l++){
                    if ((points[l][0]-x1)*(y2-y1) == (points[l][1]-y1)*(x2-x1)){
                        cnt++;
                    }
                }
                if (cnt > ret){
                    ret = cnt;
                }
            }
        }
        return ret;  
    }
}