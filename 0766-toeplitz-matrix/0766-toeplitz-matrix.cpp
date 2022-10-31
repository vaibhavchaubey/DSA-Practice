class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        for(int r = 0; r < n; r++){
            for(int c = 0; c < m; c++){
               if(r > 0 && c > 0 && matrix[r-1][c-1] != matrix[r][c]){
                   return false;
               }
            }
        }
        
        return true;
    }
};

