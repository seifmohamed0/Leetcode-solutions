class Solution {
    public String addBinary(String a, String b) {
        StringBuilder s = new StringBuilder();
        int ptr1 = a.length() - 1;
        int ptr2 = b.length() - 1;
        int carry = 0;
        while(ptr1 >= 0 || ptr2 >= 0){
            if(ptr1 >= 0){
                carry += a.charAt(ptr1--) - '0';
            }
            if(ptr2 >= 0){
                carry += b.charAt(ptr2--) - '0';
            }
            s.append((char)((carry % 2) + '0'));
            carry /= 2;
        }
        if(carry > 0)
            s.append((char)(carry + '0'));
        return s.reverse().toString();
    }
}