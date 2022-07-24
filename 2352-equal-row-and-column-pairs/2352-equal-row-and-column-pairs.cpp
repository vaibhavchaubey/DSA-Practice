class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> mat(n,vector<int>(n,0));
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                mat[i][j] = grid[j][i];
            }
        }
        
        int count = 0, cnt = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                count = 0;
                for(int k = 0; k < n; k++){
                    if(grid[i][k] == mat[j][k]){
                        count++;
                    }
                    else{
                        break;
                    }
                }
                if(count == n){
                    cnt++;
                }
            }
        }
        
        return cnt;

        
    }
};