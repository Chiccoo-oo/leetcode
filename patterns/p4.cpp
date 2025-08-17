#include <bits/stdc++.h>
using namespace std;

void p4(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << i;
        }
        cout << endl;
    }
}

int main()
{
    int p;
    cin >> p;
    p4(p);
}