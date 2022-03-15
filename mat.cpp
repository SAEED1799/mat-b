#include "mat.hpp"
#include <vector>
#include <iostream>
#include <string>
using namespace ariel;
const int maxAsciiSym = 126;
const int minAsciiSym = 33;

// checking if matrix boundaries are not negative
// bool check(int i, int j)
// {
//     if (i < 0 || j < 0)
//     {
//         return (i < 0)||(j<0) ;
//     }
//     return (i >= 0)||(j>=0) ;
// }
namespace ariel{
    string mat(int num2, int num1, char a, char b){


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
   
        //char arr[num1][num2];
        vector<vector<char>> arr( num1, vector<char>( num2 ) );
        int row=0;
        int cols=0;
        int x=num1-1;
        int y= num2-1;
        char z=a;

        while (x>-1&&y>-1)
        {
            if(row%2==0&&cols%2==0)
            {z=a;}
            else{z=b;}
            /*
            1 1 1 
            - - - 
            - - -
            */
           for (int i = row; i <= y; i++)
           {
               arr[row][i]=z;/* code */
           }
            /*
            1 1 1 
            - - - 
            1 1 1
            */
            for (int i = row; i <= y; i++)
           {
               arr[x][i]=z;/* code */
           }
            for (int i = cols; i <= x; i++)
           {
               arr[i][cols]=z;/* code */
           }
            for (int i = cols; i <= x; i++)
           {
               arr[i][y]=z;/* code */
           }
            
            
           row=row+1;
           cols=cols+1;
           x=x-1;
           y=y-1;
            /* code */
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
