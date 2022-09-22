class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int n = s.size() , m = t.size();
        int bc1 = 0 , bc2 = 0 , ptr1 = n - 1 , ptr2 = m - 1;
        while(ptr1 >= 0 || ptr2 >= 0){
           if(ptr1 == -1 && ptr2 == -1)
               return true;
            while(ptr1 >= 0 && (bc1 || s[ptr1] == '#')){
                if(s[ptr1] != '#' && bc1){
                    --bc1;
                    --ptr1;
                }else if(s[ptr1] == '#'){
                    --ptr1;
                    ++bc1;
                }
            }
            while(ptr2 >= 0 && (bc2 || t[ptr2] == '#')){
                if(t[ptr2] != '#' && bc2){
                    --bc2;
                    --ptr2;
                }else if(t[ptr2] == '#'){
                    --ptr2;
                    ++bc2;
                }
            }
            if(ptr1 < 0 && ptr2 < 0)
                return true;
            if(ptr1 < 0 || ptr2 < 0)
                return false;
            if(s[ptr1] != t[ptr2])
                return false;
            --ptr1 , --ptr2;
        }
        return true;
    }
};