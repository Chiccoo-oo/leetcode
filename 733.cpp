class Solution
{
public:
    bool valid(vector<vector<int>> &image, int r, int c)
    {
        if (r < 0 || c < 0 || r >= image.size() || c >= image[0].size())
        {
            return false;
        }
        return true;
    }

    void dfs(vector<vector<int>> &image, int r, int c, int old, int newc)
    {
        if (!valid(image, r, c))
            return;
        if (image[r][c] != old)
            return;

        image[r][c] = newc;
        dfs(image, r + 1, c, old, newc);
        dfs(image, r - 1, c, old, newc);
        dfs(image, r, c + 1, old, newc);
        dfs(image, r, c - 1, old, newc);
    }

    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {
        int old = image[sr][sc];
        if (old == color)
        {
            return image;
        }
        dfs(image, sr, sc, old, color);
        return image;
    }
};
