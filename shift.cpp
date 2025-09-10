#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        string s;
        cin >> n >> s;

        int z = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '0')
                z++;
        }

        if (z == 0 || z == n)
        {
            cout << 0 << "\n";
            continue;
        }

        int mo = 0;
        for (int i = 0; i < z; i++)
        {
            if (s[i] == '1')
                mo++;
        }

        int mz = 0;
        for (int i = z; i < n; i++)
        {
            if (s[i] == '0')
                mz++;
        }


        cout << min(mo, mz) << "\n";
    }

    return 0;
}