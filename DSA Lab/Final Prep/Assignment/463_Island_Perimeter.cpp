#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int islandPerimeter(vector<vector<int>> &grid)
    {
        int perimeter = 0;
        int rows = grid.size();
        int cols = grid[0].size();

        for (int i = 0; i < rows; ++i) // traversing each cell in the grid
        {
            for (int j = 0; j < cols; ++j)
            {
                if (grid[i][j] == 1) // cell is land
                {
                    if (i == 0 || grid[i - 1][j] == 0) // if first row or the cell above is water
                    {
                        perimeter++;
                    }
                    if (i == rows - 1 || grid[i + 1][j] == 0) // if last row or the cell below is water
                    {
                        perimeter++;
                    }
                    if (j == 0 || grid[i][j - 1] == 0) // if first column or the left cell is water
                    {
                        perimeter++;
                    }
                    if (j == cols - 1 || grid[i][j + 1] == 0) // if last column or the right cell is water
                    {
                        perimeter++;
                    }
                }
            }
        }
        return perimeter; // returning total parameter
    }
};
int main()
{
    Solution sol;
    vector<vector<int>> grid = {
        {0, 1, 0, 0},
        {1, 1, 1, 0},
        {0, 1, 0, 0},
        {1, 1, 0, 0}};
    cout << sol.islandPerimeter(grid) << endl;
    return 0;
}
