#include "mat.hpp"
#include <vector>
#include <iostream>
#include <string>
using namespace ariel;
string ariel::mat(int num1, int num2, char a, char b){
    if(num1<0 || num2<0){
    return "not good";
    } 
   std::vector<vector<char>> x;
   if(num1>2||num2>2)
   {
       
   for (int i = 0; i < num1; i++)
    {
        x[i][0]=a;
        x[i][num2-1]=0;
    }
    for (int i = 0; i < num2; i++)
    {
        x[0][i]=a;
        x[num1-1][i]=0;
    }
    if(num1>2&&num2>2){

    for (int i = 1; i < num1-1; i++)
    {
     for (int j = 1; j < num2-1; j++)
     {
         if(x[i-1][j-1]==a)
         {
           x[i][j]=b;
         }
         else 
         if(x[i-1][j-1]==b) 
         { 
            x[i][j]=a;
     }
    }
    }
    }
   }
   string saeed = "";
   for (int i = 0; i < num1; i++)
    {
     for (int j = 0; j < num2; j++)
     {
         saeed += x[j][i];
     }
     saeed += "\n";
    }
     

    
    return "saeed";

}