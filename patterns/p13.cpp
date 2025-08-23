#include <bits/stdc++.h>
using namespace std;

void p13(int n)
{
    int start = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << start << ' ';
            start += 1;
        }
        cout << endl;
    }
}

int main()
{
    int n;
    cin >> n;
    p13(n);
}