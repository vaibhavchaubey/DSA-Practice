class Solution {
public:
    int solve(int i, int j, int m, int n, vector<vector<int>> &grid){
        if(i >= m || j >= n) return 0;
        if(i == m-1 && j == n-1) return 1;
        if(grid[i][j]) return grid[i][j];
                                    //down             //right
        return grid[i][j] = solve(i+1,j,m,n,grid) + solve(i,j+1,m,n,grid);        
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> grid(m,vector<int>(n,0));
        return solve(0,0,m,n, grid);
    }
};




// The Below solution had a lot of redundant calculations. There are many cells which we reach multiple times and calculate the answer for it over and over again. However, the number of unique paths from a given cell (i,j) to the end cell is always fixed. So, we dont need to calculate and repeat the same process for a given cell multiple times. We can just store (or memoize) the result calculated for cell (i, j) and use that result in the future whenever required.
// Thus, here we use a 2d array grid, where grid[i][j] denote the number of unique paths from cell (i, j) to the end cell (m-1, n-1). Once we get an answer for cell (i, j), we store the result in grid[i][j] and reuse it instead of recalculating it.

//Brute Force  (Give TLE)

// class Solution {
// public:
//     int solve(int i, int j, int m, int n){
//         if(i >= m || j >= n) return 0;
//         if(i == m-1 && j == n-1) return 1;
//                    //down             //right
//         return solve(i++,j,m,n) + solve(i,j++,m,n);        
//     }
//     int uniquePaths(int m, int n) {
//         return solve(0,0,m,n);
//     }
// };