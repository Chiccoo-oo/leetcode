#include <bits/stdc++.h>
using namespace std;

void p7(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << ' ';
        }
        for (int j = 0; j < 2 * i + 1; j++)
        {
            cout << '*';
        }
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << ' ';
        }
        cout << endl;
    }
}

void p8(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            cout << ' ';
        }
        for (int j = 0; j < 2 * n - (2 * i + 1); j++)
        {
            cout << '*';
        }
        for (int j = 0; j < i; j++)
        {
            cout << ' ';
        }
        cout << endl;
    }
}

int main()
{
    int n;
    cin >> n;
    p7(n);
    p8(n);
}