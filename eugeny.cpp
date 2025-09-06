#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    int c1 = 0;
    int c2 = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (arr[i] == 1)
            c1++;
        else
            c2++;
    }
    for (int i = 0; i < m; i++)
    {
        int l, r;
        cin >> l >> r;
        int len = r - l + 1;
        if (len % 2 == 0)
        {
            int half = len / 2;
            if (c1 >= half && c2 >= half)
            {
                cout << 1 << "\n";
            }
            else
                cout << 0 << "\n";
        }
        else
        {
            cout << 0 << "\n";
        }
    }
    return 0;
}