class Solution {
public:
    int findMax(int row_start, int col_start, vector<vector<int>>& grid){
        int maxValue = 0;        
        for(int i = row_start; i < row_start + 3; i++){
            for(int j = col_start; j < col_start + 3; j++){
                maxValue = max(maxValue,grid[i][j]);
            }
        }
        
        return maxValue;
    }
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>>ans(n-2,vector<int>(n-2,0));
        
        for(int k = 0; k < n-2; k++){
            for(int l = 0; l < n-2; l++){
                int ele = findMax(k,l,grid);
                ans[k][l] = ele;
            }
        }
        
        return ans;
    }
};