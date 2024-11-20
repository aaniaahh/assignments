/*****************************************************************************
*
*  Names:           Aniah Myles and Prof. Terry Griffin
*  Email:           aamyles1222@my.msutexas.edu
*  Label:           06-P01
*  Title:           Fraction Class
*  Course:          CMPS 2143
*  Semester:        Fall 2024
*
*  Description:
*       This program will perform mathematical operations on fractions. It will 
*       receive two fractions separatedby a mathematical operator, then perform 
*       the operations, and provide the simplified fraction.
*
*  Files:
*       Fraction.cpp   : driver program
*       input.txt      : input file
*****************************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include "Fraction.h"

using namespace std;

// Opening the input file
void openFiles(ifstream& infile)
{
    char inFileName[40];

    cout << "Enter the input file name: ";
    cin >> inFileName;
    infile.open(inFileName); // open the input file

    if (!infile)
    {
        cout << "Error opening file!" << endl;
        exit(-1);
    }
}

int main(int argc, char const* argv[]) {

    // access and open the infile streams
      ifstream infile;
      openFiles(infile);
     
    // declare the variables
      Fraction frac1, frac2;
      char oper;

    // read in the numbers from the infile
      while (infile >> frac1 >> oper >> frac2)
      {
          cout << frac1 << oper << frac2; // print the fractions from infile
          Fraction result;

          if (oper == '+')
          {
              result = frac1 + frac2;  // This should call the overloaded + operator
              cout << result << endl; // print the results
          }
          else if (oper == '-')
          {
              result = frac1 - frac2; // This should call the overloaded - operator
              cout << result << endl; // print the results
          }
          else if (oper == '*')
          {
              result = frac1 * frac2; // This should call the overloaded  operator
              cout << result << endl; // print the results
          }
          else if (oper == '/')
          {
              result = frac1 / frac2; // This should call the overloaded / operator
              cout << result << endl; // print the results
          }
          else
              cout << "Operator does not exist." << endl;
      }

   // close the input file
   infile.close();
    return 0;
}