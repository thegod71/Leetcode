class Solution {
public:
    static const int MOD = 1e9 + 7;
    int m, n;
    vector<vector<int>> g;
    vector<int> memo; // flat [i][j][d]

    int solve(int i, int j, int d) {
        if (i >= m || j >= n) return 0;

        int &res = memo[(i * n + j) * 2 + d];
        if (res != -1) return res;

        if (g[i][j] == 1) {
            // mirror: right -> go down, down -> go right
            if (d == 0) return res = solve(i + 1, j, 1);
            else        return res = solve(i, j + 1, 0);
        }

        if (i == m - 1 && j == n - 1) return res = 1;

        return res = (solve(i, j + 1, 0) + solve(i + 1, j, 1)) % MOD;
    }

    int uniquePaths(vector<vector<int>>& grid) {
        g = grid;
        m = grid.size();
        n = grid[0].size();
        memo.assign(m * n * 2, -1);
        return solve(0, 0, 0);
    }
};