class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        map<string ,bool>words , vis;
        for(auto it : wordList)
            words[it] = true;
        if(words.find(endWord) == words.end()){
            return 0;
        }
        
        queue<pair<string , int >>q;
        q.push({beginWord , 1});
        
        while(!q.empty()){
            auto [word , d] = q.front();
            q.pop();
            if(word == endWord){
                return d;
            }
            for(auto &it : word){
                char tmp = it;
                for(char c = 'a' ; c <= 'z' ; c++){
                    it = c;
                    if(words.find(word) != words.end() && vis.find(word) == vis.end()){
                        q.push({word , d + 1});
                        vis[word];
                        
                    }
                }
                it = tmp;
            }
        }
        
        return 0;
    }
};