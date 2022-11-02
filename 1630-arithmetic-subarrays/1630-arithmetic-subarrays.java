class Solution {
    public List<Boolean> checkArithmeticSubarrays(int[] nums, int[] l, int[] r) {
        List<Boolean> ret = new ArrayList<Boolean>();
        for(int i = 0 ; i < l.length ; i++){
            ret.add(solve(nums , l[i] , r[i]));
        }
        return ret;
    }
    private boolean solve(int[] nums , int l , int r){
        if(r - l < 2)
            return true;
        int min=Integer.MAX_VALUE, max=Integer.MIN_VALUE;
        Set<Integer> st = new HashSet<Integer>();
        for(int i = l ; i <= r ; i++){
            min = Math.min(min , nums[i]);
            max = Math.max(max , nums[i]);
            st.add(nums[i]);
        }
        if((max - min) % (r - l) != 0) return false;
        int interval = (max - min) / (r -l);
        
        for(int i = 1; i <= r - l; i++) {
            if(!st.contains(min + i * interval)) return false;
        }
        return true;
    }
}