#include "mat.hpp"
#include <stdexcept>
#include <iostream>

namespace ariel
{
    string mat(int col, int row, char sym1, char sym2)
    {
        if (col % 2 == 0 || row % 2 == 0 || col < 0 || row < 0)
        {
            throw invalid_argument("Invalid syntax.");
        }
        string ans = string("");
        int plus = min(col, row);
        char mymat[row][col];
        char symball = sym1;
        for (int i = 0; i < plus; i++)
        {
            for (int r = 0; r < row; r++)
            {
                for (int c = 0; c < col; c++)
                {
                    mymat[r][c] = symball;
                    mymat[(row - 1) - i][c] = symball;
                }
            }
        }
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                ans += sym1;
                if (j == col - 1)
                {
                    ans += '\n';
                }
            }
        }
        return ans;
    }
}