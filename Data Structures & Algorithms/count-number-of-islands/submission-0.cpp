class Solution {
private: 
    void dfs(vector<vector<char>>& grid, int r, int c){
        int rows = grid.size();
        int cols = grid[0].size();
        // Boundary + water check
        if (r < 0 || c < 0 || r >= rows || c >= cols || grid[r][c] == '0')
            return;

        // Mark visited
        grid[r][c] = '0';

        // Explore 4 directions
        dfs(grid, r+1, c);
        dfs(grid, r-1, c);
        dfs(grid, r, c+1);
        dfs(grid, r, c-1);
    }

public:
    int numIslands(vector<vector<char>>& grid) {

        if (grid.empty()) return 0;

        int rows = grid.size();
        int cols = grid[0].size();
        int count = 0;

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {

                if (grid[r][c] == '1') {
                    count++;
                    dfs(grid, r, c);
                }
            }
        }

        return count;
    }

};