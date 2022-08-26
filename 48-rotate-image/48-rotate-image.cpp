class Solution {
public:
    //Rotate Matrix = Transpose Matrix + Reverse Matrix 
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        //Transpose Matrix
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        
        //Reverse Matrix
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n/2; j++){
                swap(matrix[i][j], matrix[i][n - j - 1]);
            }
        }
        
    }
};