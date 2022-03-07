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