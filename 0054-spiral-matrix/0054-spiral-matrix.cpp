class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int xd[] = {0,1,0,-1};
        int yd[] = {1,0,-1,0};
        int n = matrix.size() , m = matrix[0].size();
        vector<int>ret;
        int x = 0 , y = 0 , cnt = 0;
        int px = 0 , py = 1;
        while(cnt != n * m){
            ret.push_back(matrix[x][y]);
            matrix[x][y] = -1000;
            cnt++;
            int ax = px + x, ay = y + py;
            if(ax >= 0 && ax < n && ay >= 0 && ay < m && matrix[ax][ay] != -1000){
                x = ax;
                y = ay;
                continue;
            }
            for(int i = 0; i < 4 ; i++){
                int nx = x + xd[i];
                int ny = y + yd[i];
                if(nx >= 0 && nx < n && ny >= 0 && ny < m && matrix[nx][ny] != -1000){
                    x = nx;
                    y = ny;
                    px = xd[i];
                    py = yd[i];
                    break;
                }
            }
        }
        return ret;
    }
};