class Solution {
public:
    int findMax(int row_start, int col_start, vector<vector<int>>& grid, int n){
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
        int maxValue = 0;
        vector<vector<int>> ans;        
        for(int k = 0; k < n-2; k++){
            vector<int> vec;
            for(int l = 0; l < n-2; l++){
                vec.push_back(findMax(k,l,grid,n));
            }
            ans.push_back(vec);
        }
        
        return ans;
    }
};