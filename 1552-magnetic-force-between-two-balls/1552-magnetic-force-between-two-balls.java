class Solution {
    public boolean valid(int[] position , int m , int mid){
        int done =1 ; 
        int last_pos = position[0];
        for(int i = 1; i < position.length ; i++){
            if(position[i] - last_pos >= mid){
                ++done;
                last_pos = position[i];
            }
        }
        return done >= m;
    }
    public int maxDistance(int[] position, int m) {
        Arrays.sort(position);
        int n = position.length;
        int l = 1 , r = position[n - 1] , mid;
        int ret = 1;
        while(r >= l){
            mid = (l + r) / 2;
            if(valid(position , m , mid)){
                ret = mid ;
                l = mid + 1;
            }else{
                r = mid - 1;
            }
        }
        return ret;
    }
}