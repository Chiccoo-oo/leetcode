#include <bits/stdc++.h>
using namespace std;

void p19(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            cout << '*';
        }
        for (int j = 0; j < 2 * i; j++)
        {
            cout << ' ';
        }

        for (int j = 0; j < n - i; j++)
        {
            cout << '*';
        }
        cout << endl;
    }
    int inis = 8;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << '*';
        }
        for (int j = 0; j < inis; j++)
        {
            cout << ' ';
        }
        for (int j = 1; j <= i; j++)
        {
            cout << '*';
        }
        inis -= 2;
        cout << endl;
    }
}

int main()
{
    int n;
    cin >> n;
    p19(n);
}