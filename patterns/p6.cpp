#include <bits/stdc++.h>
using namespace std;
void p6(int n)
{
    for (int i = n; i > 0; i--)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << j << ' ';
        }
        cout << endl;
    }
}

int main()
{
    int n;
    cin >> n;
    p6(n);
}