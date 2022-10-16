class MinStack {
    Stack<Integer>st = new Stack<Integer>();
    Stack<Integer>mn = new Stack<Integer>();
    public MinStack() {

    }
    
    public void push(int val) {
        st.push(val);
        if(mn.empty())
            mn.push(val);
        else mn.push(Math.min(val , mn.peek()));
    }
    
    public void pop() {
        st.pop();
        mn.pop();
    }
    
    public int top() {
        return st.peek();
    }
    
    public int getMin() {
        return mn.peek();
    }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(val);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */