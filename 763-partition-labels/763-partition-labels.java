class Solution {
    public List<Integer> partitionLabels(String s) {
        int[] frq = new int[26];
        int tot = 0;
        int cnt = 0;
        List<Integer> ret = new ArrayList();
        for(int i = 0; i < s.length() ; i++){
            frq[s.charAt(i) - 'a']++;
        }
        for(int i = 0; i < s.length() ; i++){
            ++cnt;
            tot+= frq[s.charAt(i) - 'a'];
            frq[s.charAt(i) - 'a'] = 0;
            if(cnt == tot){
                ret.add(tot);
                tot = 0;
                cnt = 0;
                
            }
        }
        return ret;
    }
}