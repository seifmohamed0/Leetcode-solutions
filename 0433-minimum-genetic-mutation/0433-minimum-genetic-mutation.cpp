class Solution {
public:

    int minMutation(string s, string t, vector<string>& bank) {
        vector<vector<int>>v(11);
        for(int i = 0; i < (int)bank.size() ; i++){
            for(int j = i + 1 ; j < bank.size() ; j++){
                int diff = 0;
                for(int k = 0 ; k < 8 ; k++){
                    if(bank[i][k] != bank[j][k])
                        ++diff;
                }
                if(diff == 1){
                    v[i].push_back(j);
                    v[j].push_back(i);
                }
            }
        }        
        
        if(s == t)
            return 0;
        
        vector<bool>vis(11);
        queue<array<int,2>>q;
        for(int i = 0; i < bank.size() ; i++){
            int diff = 0;
            for(int k = 0; k < 8 ; k++){
                if(bank[i][k] != s[k])
                    ++diff;
            }
            if(diff == 1){
                if(bank[i] == t){
                    return 1;
                }
                vis[i] = true;
                q.push({i , 1});
            }
        }
        
        while(!q.empty()){
            array<int,2>curr = q.front();
            q.pop();
            for(auto it : v[curr[0]]){
                if(!vis[it] ){
                    if(bank[it] == t){
                        return curr[1] + 1;
                    }
                    vis[it] = true;
                    q.push({it , curr[1] + 1});
                }
            }
        }
        
        return -1;
    }
};