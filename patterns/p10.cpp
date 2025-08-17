#include <bits/stdc++.h>
using namespace std;

void p3(int n)
{
    for (int i = n - 1; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            cout << '*' << ' ';
        }
        cout << endl;
    }
}
void p2(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << '*' << ' ';
        }
        cout << endl;
    }
}

int main()
{
    int n;
    cin >> n;
    p2(n);

    p3(n);
}