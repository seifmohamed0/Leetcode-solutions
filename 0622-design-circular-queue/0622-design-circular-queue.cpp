class MyCircularQueue {
public:
    vector<int>v;
    int ptr1 , ptr2;
    int sz;
    MyCircularQueue(int k) {
        ptr1 = ptr2 = 0;
        sz = k;
    }
    
    bool enQueue(int value) {
        if(ptr2 - ptr1 == sz)
            return false;
        v.push_back(value);
        ++ptr2;
        return true;
    }
    
    bool deQueue() {
        if(ptr2 - ptr1 == 0)
            return false;
        ++ptr1;
        return true;
    }
    
    int Front() {
        if(ptr2 - ptr1 == 0)
            return -1;
        return v[ptr1];
    }
    
    int Rear() {
        if(ptr2 - ptr1 == 0)
            return -1;
        return v[ptr2 - 1];
    }
    
    bool isEmpty() {
        return ptr2 - ptr1 == 0;
    }
    
    bool isFull() {
        return ptr2 - ptr1 == sz;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */