
#include <iostream>
#include <sstream>
#include <cmath>
#include "Fraction.h"

    // Constructor
   Fraction::Fraction() : numerator(1), denominator(1){}
   Fraction :: Fraction(int num, int den) : numerator(num), denominator(den) 
    {
        if (den == 0) // Consider validating that denominator is not 0
        {
            cout << "ERROR! Denominator cannot ever be 0!" << endl;
            denominator = 1;
            exit(0);
        }
        else
        {
            numerator = num;
            denominator = den;
        }
    }
    // Overload input operator (>>)
   istream& operator>>(istream& is, Fraction& frac)
   {
       // declare the variable
       char slash;

       // read in the fractions
       is >> frac.numerator >> slash >> frac.denominator;
       return is;
   }

    // Overload output operator (<<) for printing fractions
   ostream& operator<<(ostream& os, const Fraction& frac)
   {
       os << frac.numerator << "/" << frac.denominator;
       return os;
   }
    // Overloaded addition operator
   Fraction Fraction :: operator+(const Fraction& other)
    {
        // TODO: Use LCM and LCD to add fractions correctly
        // Add comments explaining how you use LCD and LCM to add fractions

        // Steps:
        // 1. Find the least common denominator (LCD)
        int lcdVal = lcd(denominator, other.denominator);

        // 2. Adjust both fractions to have this denominator
        int numerator1 = numerator * (lcdVal / denominator);
        int numerator2 = other.numerator * (lcdVal / other.denominator);

        // 3. Add the numerators
        int resultNumerator = numerator1 + numerator2;

        // 4. Simply the fraction answered 
        Fraction results(resultNumerator, lcdVal);
        results.reduceFrac();

        // 4. Return the result as a simplified fraction
        return results;
    }

    // Additional overloaded operators (students should implement these)
    // Overloaded subtraction operator
    Fraction Fraction :: operator-(const Fraction& other) 
    {
        // TODO: Implement the subtraction logic
         // 1. Find the least common denominator (LCD)
        int lcdVal = lcd(denominator, other.denominator);

        // 2. Adjust both fractions to have this denominator
        int numerator1 = numerator * (lcdVal / denominator);
        int numerator2 = other.numerator * (lcdVal / other.denominator);

        // 3. Add the numerators
        int resultNumerator = numerator1 - numerator2;

        // 4. Simply the fraction answered 
        Fraction results(resultNumerator, lcdVal);
        results.reduceFrac();

        // 4. Return the result as a simplified fraction
        return results;
    }

    // Overloaded multiplication operator
    Fraction Fraction :: operator*(const Fraction& other)
    {
       // TODO: Implement the multiplication logic
        // 1. Multiply the numerators
        int resultNumerator = numerator * other.numerator;

        // 2. Multiply the denominators
        int resultDenominator = denominator * other.denominator;

        // 3. Simplify the fraction answered
        Fraction results(resultNumerator, resultDenominator);
        results.reduceFrac();

        // 4. Return the result as a simplified fraction
        return results;
    }

    // Overloaded division operator
    Fraction Fraction :: operator/(const Fraction& other)
    {
        // TODO: Implement the division logic
         // 1. Do fraction 1 * the reciprocal of fraction 2
        int resultNumerator = numerator * other.denominator;
        int resultDenominator = denominator * other.numerator;

        // 2. Simplify the fraction answered
        Fraction results(resultNumerator, resultDenominator);
        results.reduceFrac();

        // 3. Return the result as a simplified fraction
        return results;
    }

    bool Fraction::operator==(const Fraction& other) const
    {
        // Compare numerators and denominators
        return (numerator == other.numerator && denominator == other.denominator);
    }

    // print how the fractions
    void Fraction :: print()
    {
        cout << numerator << "/" << denominator << endl;
    }

// Function to reduce the fraction 
void Fraction :: reduceFrac()
{
    int gcdVal = gcd(numerator, denominator);
    numerator = numerator / gcdVal; // dividing the num by gcd
    denominator = denominator / gcdVal; // dividing the den by gcd
}

//Function to calculate the Greatest Common Denominator (GCD)
int Fraction::gcd(int a, int b)
{
    //calculate the gcd
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to calculate Least Common Denominator (LCD)
int Fraction::lcd(int a, int b) 
{
    // TODO: Implement logic for LCD:  
   // set the variables to their absolute values
    a = abs(a);
    b = abs(b);

    // declare the variables
    int lcdVal = (a * b) / gcd(a, b);

    // return the lcd
    return lcdVal;

}

// Function to calculate Least Common Multiple (LCM)
int Fraction::lcm(int a, int b) 
{
    // TODO: Implement logic for LCM
   // set the variables to their absolute values
    a = abs(a);
    b = abs(b);

    // declare the variables
    int lcmVal = (a * b) / gcd(a, b);


    // return the lcm
    return lcmVal;

}