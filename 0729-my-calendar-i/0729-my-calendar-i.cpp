class MyCalendar {
public:
    set<int>s , e;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        --end;
        if(s.empty()){
            s.insert(start);
            e.insert(end);
            return true;
        }
        auto it = s.upper_bound(start);
        if(it == s.begin()){
            auto it2 = e.lower_bound(*it);
            if((start >= (*it) && start <= (*it2)) || (end >= (*it) && end <= (*it2)))
                return false;
            if((*it) >= start && (*it) <= end)
                    return false;
        }else{
            --it;
            if(*it == start)
                return false;
            auto it2 = e.lower_bound(*it);
            if(start >= (*it) && start <= (*it2))
                return false;
            ++it;
            if(it != s.end()){
                it2 = e.lower_bound(*it);
                if((start >= (*it) && start <= (*it2)) || (end >= (*it) && end <= (*it2)))
                    return false;
                if((*it) >= start && (*it) <= end)
                    return false;
            }
        }
        s.insert(start);
        e.insert(end);
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */