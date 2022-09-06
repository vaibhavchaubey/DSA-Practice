class Solution {
public:
    int countPaths(int i, int j, int m, int n, vector<vector<int>> &grid){
        if(i >= m || j >= n) return 0;
        if(i == m-1 && j == n-1) return 1;
        if(grid[i][j] != -1) return grid[i][j];
                                    //down             //right
        return grid[i][j] = countPaths(i+1,j,m,n,grid) + countPaths(i,j+1,m,n,grid);        
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> grid(m,vector<int>(n,-1));
        return countPaths(0,0,m,n, grid);
    }
};

//Time Complexity : O(m*n)
//Space Complexity : O(m*n)



// The Below solution had a lot of redundant calculations. There are many cells which we reach multiple times and calculate the answer for it over and over again. However, the number of unique paths from a given cell (i,j) to the end cell is always fixed. So, we dont need to calculate and repeat the same process for a given cell multiple times. We can just store (or memoize) the result calculated for cell (i, j) and use that result in the future whenever required.
// Thus, here we use a 2d array grid, where grid[i][j] denote the number of unique paths from cell (i, j) to the end cell (m-1, n-1). Once we get an answer for cell (i, j), we store the result in grid[i][j] and reuse it instead of recalculating it.

//Brute Force  (Give TLE)

// class Solution {
// public:
//     int countPaths(int i, int j, int m, int n){
//         if(i >= m || j >= n) return 0;
//         if(i == m-1 && j == n-1) return 1;
//                    //down             //right
//         return countPaths(i+1,j,m,n) + countPaths(i,j+1,m,n);        
//     }
//     int uniquePaths(int m, int n) {
//         return countPaths(0,0,m,n);
//     }
// };

//Time Complexity : O(2^m+n)
//Space Complexity : O(m+n)