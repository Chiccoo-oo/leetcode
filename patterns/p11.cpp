#include <iostream>
using namespace std;

void p11(int n)
{
    for (int i = 1; i <= n; i++)
    {

        int start = (i % 2 == 1) ? 1 : 0;

        for (int j = 1; j <= i; j++)
        {

            cout << start << " ";

            start = 1 - start;
        }
        cout << endl;
    }
}

int main()
{
    int n;
    cout << "Enter the number of rows: ";
    cin >> n;
    p11(n);
    return 0;
}