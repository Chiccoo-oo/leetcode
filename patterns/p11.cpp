#include <iostream>
using namespace std;

void p11(int n)
{
    for (int i = 1; i <= n; i++)
    {
        // Determine the starting number for the current row.
        // If the row number (i) is odd, the starting number is 1.
        // If the row number (i) is even, the starting number is 0.
        int start = (i % 2 == 1) ? 1 : 0;

        for (int j = 1; j <= i; j++)
        {
            // Print the number and a space.
            cout << start << " ";

            // Toggle the number for the next iteration.
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