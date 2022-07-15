class Solution {
public:
    int area(vector<vector<int>>& grid, int r, int c){
        if(r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size() || grid[r][c] == 0){
            return 0;
        }
        //after backtracking make neighbour 0 so that it will not interfare in further iterations
        grid[r][c] = 0;
        //              above              below              right              left
        return (1 + area(grid,r+1,c) + area(grid,r-1,c) + area(grid,r,c+1) + area(grid,r,c-1));
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        for(int r = 0; r < grid.size(); r++){
            for(int c = 0; c < grid[0].size(); c++){
                if(grid[r][c] == 1){
                    int count = area(grid,r,c);
                    ans = max(ans,count);
                }
            }
        }
        
        return ans;
    }
};