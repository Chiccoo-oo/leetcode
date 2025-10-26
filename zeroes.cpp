#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long n;
    cin >> n;
    string s = to_string(n);
    string r = "";

    for (char c : s)
    {
        if (c != '0')
        {
            r += c;
        }
    }
    cout << r;
    return 0;
}