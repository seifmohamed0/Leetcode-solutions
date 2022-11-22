/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    queue<int>q;
    void get_values(NestedInteger ni){
        if(ni.isInteger()){
            q.push(ni.getInteger());
        }else{
            for(auto it : ni.getList())
                get_values(it);
        }
    }
    NestedIterator(vector<NestedInteger> &nestedList) {
        for(auto it : nestedList){
            get_values(it);
        }    
    }
    
    int next() {
        int ret;
        if(hasNext()){
            ret = q.front();
            q.pop();
        }
        return ret;
    }
    
    bool hasNext() {
        if(!q.empty())
            return true;
        return false;
    }
};
/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */