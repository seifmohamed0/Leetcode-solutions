class Solution {
    public int evalRPN(String[] tokens) {
        Stack<Integer>st = new Stack<Integer>();
        for(int i = 0; i < tokens.length ; i++){
            if(tokens[i].equals("*")|| tokens[i].equals("-") || tokens[i].equals("+")|| tokens[i].equals("/")){
                int a = st.pop();
                int b = st.pop();
                if(tokens[i].equals("*"))
                    a *= b;
                else if(tokens[i].equals("+"))
                    a += b;
                else if(tokens[i].equals("-"))
                    a = b - a;
                else a = b / a;
                st.push(a);
            }else{
                int state = 1;
                int ptr = 0;
                if(tokens[i].charAt(0) == '-' ){
                    state = -1;
                    ++ptr;   
                }
                int num = 0;
                for(; ptr < tokens[i].length() ; ptr++){
                    num *= 10;
                    num += tokens[i].charAt(ptr) - '0';
                }
                st.push(num * state);
            }
        }
        return st.peek();
    }
}