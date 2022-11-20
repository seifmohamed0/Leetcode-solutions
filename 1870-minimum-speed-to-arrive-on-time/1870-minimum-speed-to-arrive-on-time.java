class Solution {
    public int minSpeedOnTime(int[] dist, double hour) {
        int n = dist.length;
        int l = 1, r = 10000000;
        int ret = -1;
        while(l <= r){
            int mid = (l + r)/2;
            double sum = 0;
            for(int i = 0; i<n-1; ++i){
                sum += Math.ceil( ( (double) dist[i]) /mid);
            }
            sum = sum + ( ( (double) dist[n-1]) /mid);
            if(sum > hour){
                l = mid+1;
            }else{
                ret = mid;
                r = mid-1;
            }
        }
        return ret;
    }
}