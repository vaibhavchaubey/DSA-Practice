class Solution {
public:
    //Rotate Matrix = Transpose Matrix + Reverse Matrix 
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        //Transposing the matrix
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        
        //Reversing each row of the matrix
        for(int i = 0; i < n; i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }
        
        //OR
        // for(int i = 0; i < n; i++){
        //     for(int j = 0; j < n/2; j++){
        //         swap(matrix[i][j], matrix[i][n - j - 1]);
        //     }
        // }
        
    }
};