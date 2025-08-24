#include <bits/stdc++.h>
using namespace std;

void p20(int n)
{
    int spaces = 2 * n - 2;
    for (int i = 1; i <= 2 * n - 1; i++)
    {
        int s = i;
        if (i > n)
            s = 2 * n - i;
        for (int j = 1; j <= s; j++)
        {
            cout << '*';
        }
        for (int j = 1; j <= spaces; j++)
        {
            cout << " ";
        }

        for (int j = 1; j <= s; j++)
        {
            cout << '*';
        }
        cout << endl;
        if (i < n)
            spaces -= 2;
        else
            spaces += 2;
    }
}

int main()
{
    int n;
    cin >> n;
    p20(n);
}