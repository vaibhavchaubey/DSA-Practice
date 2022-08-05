class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int col0 = 1, R = matrix.size(), C = matrix[0].size();
        
        for(int i = 0; i < R; i++){
            if(matrix[i][0] == 0){
                col0 = 0;
            }
            for(int j = 1; j < C; j++){
                if(matrix[i][j] == 0){
                    matrix[i][0] = matrix[0][j] = 0;
                }
            }
        }
        
        for(int i = R-1; i >= 0 ; i--){
            for(int j = C-1; j >= 1; j--){
                if(matrix[i][0] == 0 || matrix[0][j] == 0){ 
                    matrix[i][j] = 0;
                }
            }
            if(col0 == 0){
                matrix[i][0] = 0;
            }
        }
        
    }
};

//Time Complexity: O(M*N)  where M and N are the number of rows and columns respectively
//Space Complexity: O(1)