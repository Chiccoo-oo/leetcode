#include <iostream>
#include <vector>
#include <numeric>

struct Result
{
    Result() : output1() {};
    int output1[100];
};

struct Result resultMatrix(int input1, int **input2)
{
    Result res;

    std::vector<int> current_points(input1, 0);

    for (int i = 0; i < input1; ++i)
    {
        for (int j = 0; j < input1; ++j)
        {
            if (input2[i][j] == 1)
            {
                current_points[i]++;
            }
            else if (input2[i][j] == 0)
            {
                current_points[j]++;
            }
        }
    }

    int max_possible_points = 0;
    for (int i = 0; i < input1; ++i)
    {
        int undecided_matches = 0;
        for (int j = 0; j < input1; ++j)
        {
            if (input2[i][j] == 2)
            {
                undecided_matches++;
            }
        }
        int possible_points = current_points[i] + undecided_matches;
        if (possible_points > max_possible_points)
        {
            max_possible_points = possible_points;
        }
    }

    for (int i = 0; i < input1; ++i)
    {
        int undecided_matches = 0;
        for (int j = 0; j < input1; ++j)
        {
            if (input2[i][j] == 2)
            {
                undecided_matches++;
            }
        }
        int max_achievable_points = current_points[i] + undecided_matches;

        if (max_achievable_points >= max_possible_points)
        {
            res.output1[i] = 1;
        }
        else
        {
            res.output1[i] = 0;
        }
    }

    return res;
}