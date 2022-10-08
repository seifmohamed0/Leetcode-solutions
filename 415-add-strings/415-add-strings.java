class Solution {
    public String addStrings(String num1, String num2) {
        int carry = 0;
        int n1 = num1.length();
        int n2 = num2.length();
        StringBuilder ret = new StringBuilder();
        int ptr1 = n1 - 1;
        int ptr2 = n2 - 1;
        while(ptr1 >= 0 || ptr2 >= 0){
            int sum = carry;
            carry = 0;
            if(ptr1 >= 0)
                sum += num1.charAt(ptr1--) - '0';
            if(ptr2 >= 0)
                sum += num2.charAt(ptr2--) - '0';
            if(sum >= 10)carry = 1;
            sum %= 10;
            ret.append(sum);
        }
        if(carry == 1)
            ret.append(carry);
        return ret.reverse().toString();
    }
}