#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void dfs(vector<vector<int>> &image, int sr, int sc, int originalColor, int newColor) // helper DFS function for recursively fill connected pixels
    {
        int rows = image.size();
        int cols = image[0].size();

        if (sr < 0 || sc < 0 || sr >= rows || sc >= cols) // base check if out-of-bounds or different color
        {
            return;
        }
        if (image[sr][sc] != originalColor || image[sr][sc] == newColor) // base check if out-of-bounds or different color
        {
            return;
        }

        image[sr][sc] = newColor; // coloring current box to new

        dfs(image, sr + 1, sc, originalColor, newColor); // calling matrixes up, down, left, right
        dfs(image, sr - 1, sc, originalColor, newColor);
        dfs(image, sr, sc + 1, originalColor, newColor);
        dfs(image, sr, sc - 1, originalColor, newColor);
    }

    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color) // initiate flood fill
    {
        int originalColor = image[sr][sc];

        if (originalColor != color)
        {
            dfs(image, sr, sc, originalColor, color); // function call
        }

        return image;
    }
};
int main() {
    vector<vector<int>> image = {
        {1, 1, 1},
        {1, 1, 0},
        {1, 0, 1}
    };
    int sr = 1, sc = 1, color = 2;

    Solution sol;
    vector<vector<int>> result = sol.floodFill(image, sr, sc, color); // function call

    for (const auto &row : result) { // for auto type detection
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
