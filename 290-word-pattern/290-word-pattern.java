class Solution {
    public boolean wordPattern(String pattern, String s) {
        String[] map = new String[26];
        int ptr1 = 0 , ptr2 = 0;
        int sz1 = pattern.length();
        int sz2 = s.length();
        HashMap<String , Character> mp= new HashMap<String , Character>();
        while(ptr1 < sz1 && ptr2 < sz2){
            StringBuilder new_s = new StringBuilder();
            while(ptr2 < sz2 && s.charAt(ptr2) != ' '){
                new_s.append(s.charAt(ptr2));
                ++ptr2;
            }
            ++ptr2;
            String new_ss = new_s.toString();
            if(mp.containsKey(new_ss)){
                if(mp.get(new_ss) != pattern.charAt(ptr1))
                   return false;
            }else{
                mp.put(new_ss , pattern.charAt(ptr1));
            }
            if(map[pattern.charAt(ptr1) - 'a'] != null){
                System.out.println(map[pattern.charAt(ptr1) - 'a'] + " " + new_ss);
                if(map[pattern.charAt(ptr1) - 'a'].equals(new_ss) == false)
                    return false;
            }else{
                map[pattern.charAt(ptr1) - 'a'] = new_ss;
            }
            
            ++ptr1;
        }
        if(ptr1 < sz1 || ptr2 < sz2)
            return false;
        
        return true;
    }
}