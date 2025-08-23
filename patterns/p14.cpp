#include <bits/stdc++.h>
using namespace std;

void p14(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (char ch = 'A'; ch <= 'A' + i; ch++)
        {
            cout << ch << ' ';
        }
        cout << endl;
    }
}

int main()
{
    int n;
    cin >> n;
    p14(n);
}