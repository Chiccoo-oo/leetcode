#include <bits/stdc++.h>

using namespace std;

void s()
{
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> p[i];
    }
    for (int i = 0; i < n; ++i)
    {
        cout << n + 1 - p[i] << (i == n - 1 ? "" : " ");
    }
    cout << endl;
}

int main()
{
   
    int t;
    cin >> t;
    while (t--)
    {
        s();
    }
    return 0;
}