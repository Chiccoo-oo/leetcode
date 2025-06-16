#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    ll k, a, b, x, y;
    cin >> k >> a >> b >> x >> y;
    ll m = 0;
    if (k >= a)
    {
        ll i = (k - a) / x + 1;
        ll t = k - i * x;
        ll j = (t >= b) ? (t - b) / y + 1 : 0;
        if (t >= 0 || i == 0)
            m = max(m, i + j);
        if (i > 0)
        {
            i--;
            t = k - i * x;
            j = (t >= b) ? (t - b) / y + 1 : 0;
            if (t >= 0 || i == 0)
                m = max(m, i + j);
        }
    }
    if (k >= b)
    {
        ll j = (k - b) / y + 1;
        ll t = k - j * y;
        ll i = (t >= a) ? (t - a) / x + 1 : 0;
        if (t >= 0 || j == 0)
            m = max(m, i + j);
        if (j > 0)
        {
            j--;
            t = k - j * y;
            i = (t >= a) ? (t - a) / x + 1 : 0;
            if (t >= 0 || j == 0)
                m = max(m, i + j);
        }
    }
    cout << m << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}