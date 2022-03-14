
//
// Created by saeed on 3/11/2022.
//

#include "mat.hpp"
#include <vector>
#include <iostream>
#include <string>
using namespace std;
using namespace ariel;
const int maxAsciiSym = 126;
const int minAsciiSym = 33;

// checking if matrix boundaries are not negative
bool check(int i, int j)
{
    if (i < 0 || j < 0)
    {
        return false;
    }
    return true;
}
     namespace ariel{
     string mat(int num2, int num1, char a, char b)
     
{

    if (num1 % 2 == 0 || num2 % 2 == 0)
    {

        throw invalid_argument("odd numbers only allowed");
    }
    if (num1 < 0 || num2 < 0)
    {
        throw invalid_argument("postive numbers only allowed");
    }
    if ((a < minAsciiSym || a > maxAsciiSym) || (b < minAsciiSym || b > maxAsciiSym))
    {
        throw invalid_argument("incorrect symbol");
    }

    // num1= rows , num2 = cols
    char arr[num1][num2];
    // vector<vector<char>> arr( num1, vector<char>( num2) );
    int sum = 0;
    // int max = num1 * num2;
    /*
      for loop for the length of the matrix
      -
      -
      -
      -
      -
      for the num2 \2
    */
    for (int i = 0; i < num2 / 2 + 1; ++i)
    {
        /**
         * 1 1 1
         * - - -
         * - - -
         */
        for (int j = i; j < num1 - i; ++j)
        {

            if (i % 2 == 0)
            {
                cout << "rows: " << i << endl;
                cout << "cols: " << j << endl;
                bool ans = check(i, j);
                if (!ans)
                {
                    continue;
                }
                arr[j][i] = a;
                sum++;
            }
            else
            {
                cout << "rows: " << i << endl;
                cout << "cols: " << j << endl;
                bool ans = check(i, j);
                if (!ans)
                {
                    continue;
                }
                cout << "rows: " << j << endl;
                cout << "cols: " << i << endl;
                //  cout << "i: " << i << " j:" << j << endl;
                arr[j][i] = b;
                sum++;
            }
        }

        /**
         * - - -
         * - - -
         * 1 1 1
         */
        for (int j = i; j < num1 - i; ++j)
        {
            if (i % 2 == 0)
            {
                cout << "cols: " << num2 - i - 1 << endl;

                bool ans = check(j, num2 - i - 1);
                if (!ans)
                {
                    continue;
                }
                arr[j][num2 - i - 1] = a;
                sum++;
            }
            else
            {

                arr[j][num2 - i - 1] = b;
                sum++;
            }
        }
        /**
         * 1 - -
         * 1 - -
         * 1 - -
         */
        for (int j = i; j < num2 - i - 1; ++j)
        {
            bool ans = check(i, j);
            if (!ans)
            {
                continue;
            }
            if (i % 2 == 0)
            {

                arr[i][j] = a;
                sum++;
            }
            else
            {
                arr[i][j] = b;
                sum++;
            }
        }
        /**
         * - - 1
         * - - 1
         * - - 1
         */
        for (int j = i; j < num2 - i - 1; ++j)
        {
            bool ans = check(num1 - i - 1, j);
            if (!ans)
            {
                continue;
            }
            if (i % 2 == 0)
            {

                arr[num1 - i - 1][j] = a;
                sum++;
            }
            else
            {

                arr[num1 - i - 1][j] = b;
                sum++;
            }
        }
    }
    string s;
    for (int i = 0; i < num1; i++)
    {
        for (int j = 0; j < num2; j++)
        {
            s += arr[i][j];
        }
        s += "\n";
    }
    // for (int k = 0; k < num1; ++k) {
    //     for (int i = 0; i < num2; ++i) {
    //         cout << arr[k][i] << " ";
    //     }
    //     cout << "\n";
    // }
    return s;
}
     }
     

// int main() {
//     std::cout << mat(4,3,'0','1') << std::endl;
//     return 0;
// }