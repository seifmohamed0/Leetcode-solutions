class MyHashMap {
    int[] mem = new int[1000005];
    public MyHashMap() {
        Arrays.fill(mem , -1);   
    }
    
    public void put(int key, int value) {
        mem[key] = value;
    }
    
    public int get(int key) {
        return mem[key];
    }
    
    public void remove(int key) {
        mem[key] = -1;
    }
}

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap obj = new MyHashMap();
 * obj.put(key,value);
 * int param_2 = obj.get(key);
 * obj.remove(key);
 */