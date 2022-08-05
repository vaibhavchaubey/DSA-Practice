class Solution {
public:
    void setRowZero(vector<int> row, int n, vector<vector<int>>& matrix){
        for(auto it : row){
            for(int i = 0; i < n; i++){
                matrix[it][i] = 0;
            }
        }
    }
    void setColZero(vector<int> col, int m, vector<vector<int>>& matrix){
        for(auto it : col){
            for(int i = 0; i < m; i++){
                matrix[i][it] = 0;
            }
        }
    }
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> row;
        vector<int> col;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == 0){
                    row.push_back(i);
                    col.push_back(j);
                }
            }
        }
        setRowZero(row,n,matrix);
        setColZero(col,m,matrix);
    }
};