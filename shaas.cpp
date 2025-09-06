#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int m;
    cin >> m;

    for (int i = 0; i < m; i++)
    {
        int xi, yi;
        cin >> xi >> yi;
        xi--; // convert to 0-based

        int t = a[xi];

        if (xi > 0)
        {
            a[xi - 1] += (yi - 1);
        }
        if (xi < n - 1)
        {
            a[xi + 1] += (t - yi);
        }
        a[xi] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << "\n";
    }

    return 0;
}
