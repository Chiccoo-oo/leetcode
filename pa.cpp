#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> p(n);
        for (int i = 0; i < n; i++)
        {
            cin >> p[i];
        }

        vector<int> q(n);
        int k = (n + 1) / 2;
        for (int i = 0; i < n; i++)
        {
            if (i % 2 == 0)
            {
                q[i] = k + i / 2;
            }
            else
            {
                q[i] = (i + 1) / 2;
            }
        }

        for (int i = 0; i < n; i++)
        {
            cout << q[i];
            if (i < n - 1)
                cout << " ";
        }
        cout << "\n";
    }
    return 0;
}