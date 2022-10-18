class Solution {
public:
    int maxSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int firstRow = 0;
        int secondRow = 0;
        int thirdRow = 0;
        
        int maxi = INT_MIN;
        
        // traverse the grid sideways
        for(int j = 2; j < m; j++) {
            firstRow = grid[j-2][0] + grid[j-2][1] + grid[j-2][2];
            secondRow = grid[j-1][1];
            thirdRow = grid[j][0] + grid[j][1] + grid[j][2];
            maxi = max(maxi, firstRow + secondRow + thirdRow);
            
            for(int i = 3; i < n; i++) {
                firstRow += grid[j-2][i] - grid[j-2][i-3];
                secondRow += grid[j-1][i-1] - grid[j-1][i-2];
                thirdRow += grid[j][i] - grid[j][i-3];
                
                maxi = max(maxi, firstRow + secondRow + thirdRow);
            }
        }
        
        return maxi;
    }
};