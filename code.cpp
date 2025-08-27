#include <bits/stdc++.h>
using namespace std;

struct Result
{
    Result() { memset(output1, 0, sizeof(output1)); }
    int output1[100];
};

struct Result resultMatrix(int input1, int input2[100][100])
{
    int maxPossible[100] = {0};
    int globalMax = 0;

    for (int i = 0; i < input1; i++)
    {
        int current = 0, remaining = 0;
        for (int j = 0; j < input1; j++)
        {
            if (input2[i][j] == 1)
                current++;
            else if (input2[i][j] == 2)
                remaining++;
        }
        maxPossible[i] = current + remaining;
        globalMax = max(globalMax, maxPossible[i]);
    }

    Result res;
    for (int i = 0; i < input1; i++)
    {
        res.output1[i] = (maxPossible[i] == globalMax) ? 1 : 0;
    }
    return res;
}

int main()
{
    int X;
    cin >> X;

    int A[100][100];
    for (int i = 0; i < X; i++)
    {
        for (int j = 0; j < X; j++)
        {
            cin >> A[i][j];
        }
    }

    Result ans = resultMatrix(X, A);

    for (int i = 0; i < X; i++)
    {
        cout << ans.output1[i] << " ";
    }
    cout << endl;
    return 0;
}