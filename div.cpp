#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<long long> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        long long s = 0;
        for (int i = 0; i < n; i++)
            s += (i % 2 ? -a[i] : a[i]);
        long long m1 = *max_element(a.begin(), a.end());
        long long m2 = *min_element(a.begin(), a.end());
        cout << max({s, m1 - a[0], a[n - 1] - m2}) << "\n";
    }
}
