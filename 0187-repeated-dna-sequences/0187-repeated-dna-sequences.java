class Solution {
    public List<String> findRepeatedDnaSequences(String s) {
        List<String> ret = new ArrayList<String>();
        HashMap<String , Integer> hm = new HashMap<String,Integer>();
        StringBuilder sb = new StringBuilder();
        int n = s.length();
        if(n < 10)
            return ret;
        for(int i = 0 ; i < 10 ; i++){
            sb.append(s.charAt(i));
        }
        hm.put(sb.toString() , 1);
        for(int i = 10 ; i < n ; i++){
            sb.deleteCharAt(0);
            sb.append(s.charAt(i));
            if(hm.containsKey(sb.toString()) == true){
                if(hm.get(sb.toString()) == 1){
                    ret.add(sb.toString());
                    hm.replace(sb.toString() , 2);
                }
            }else{
                hm.put(sb.toString() , 1);
            }
        }
        return ret;
    }
}