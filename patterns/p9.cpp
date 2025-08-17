#include <iostream>

void p7(int n)
{
    for (int i = 0; i < n; i++)
    {
        // Number of leading spaces
        for (int j = 0; j < n - i - 1; j++)
        {
            std::cout << " ";
        }
        // Number of stars
        for (int j = 0; j < 2 * i + 1; j++)
        {
            std::cout << "*";
        }
        std::cout << std::endl;
    }
}

void p8(int n)
{
    // The loop should go from n-2 down to 0, because the top
    // pattern has n rows (0 to n-1), and we want to print
    // the inverted pattern from the (n-2)th row down to the 0th row
    // to avoid duplicating the widest row and to create a symmetrical pattern.
    for (int i = n - 2; i >= 0; i--)
    {
        // The number of spaces and stars should be the same as in p7
        // for the corresponding row 'i'.

        // Number of leading spaces
        for (int j = 0; j < n - i - 1; j++)
        {
            std::cout << " ";
        }
        // Number of stars
        for (int j = 0; j < 2 * i + 1; j++)
        {
            std::cout << "*";
        }
        std::cout << std::endl;
    }
}

int main()
{
    int n;
    std::cout << "Enter the number of rows for the top half: ";
    std::cin >> n;
    p7(n);
    p8(n);
    return 0;
}