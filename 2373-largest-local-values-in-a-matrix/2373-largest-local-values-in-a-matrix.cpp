class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>>ans(n-2,vector<int>(n-2,0));
        
        for(int k = 0; k < n-2; k++){
            for(int l = 0; l < n-2; l++){
                for(int i = k; i < k + 3; i++){
                    for(int j = l; j < l + 3; j++){
                        ans[k][l] = max(ans[k][l], grid[i][j]);
                    }
                }
            }
        }
        
        return ans;
    }
};