class Solution {
    public int subarraySum(int[] nums, int k) {
        HashMap<Integer , Integer> mp = new HashMap<Integer , Integer>();
        mp.put(0 , 1);
        int sum = 0;
        int ret = 0;
        for(int num : nums){
            sum += num;
            if(mp.containsKey(sum - k)){
                ret += mp.get(sum - k);
            }
            if(mp.containsKey(sum))
                mp.replace(sum , mp.get(sum) + 1);
            else mp.put(sum , 1);
        }
        return ret;
    }
}