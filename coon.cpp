#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> a(n, vector<int>(m));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> a[i][j];

        
        int ans = INT_MAX;
        vector<pair<int, int>> corners = {{0, 0}, {0, m - 1}, {n - 1, 0}, {n - 1, m - 1}};
        for (auto [r, c] : corners)
        {
            int max_val = 0;
            for (int i = 0; i < n; i++)
                for (int j = 0; j < m; j++)
                {
                    int val = a[i][j];
                    if (i == r || j == c)
                        val--;
                    max_val = max(max_val, val);
                }
            ans = min(ans, max_val);
        }
        cout << ans << "\n";
    }
    return 0;
}
