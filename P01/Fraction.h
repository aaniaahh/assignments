#pragma once
//Fraction.h
// Aniah Myles and Prof. Terry Griffin


#ifndef Fraction_h
#define Fraction_h
#include <iostream>
#include <sstream>
using namespace std;


class Fraction {
private:
    int numerator;
    int denominator;

public:
    // Constructor
    Fraction();
    Fraction(int num, int den); // default numerator and denominator

    // The Overloads Operators
 
    friend istream& operator>>(istream& is, Fraction& frac); // read in fractions

    friend ostream& operator<<(ostream& os, const Fraction& frac); // printing function

    Fraction operator+(const Fraction& other); // addition function

    Fraction operator-(const Fraction& other); // subtraction function

    Fraction operator*(const Fraction& other); // multiplication function

    Fraction operator/(const Fraction& other); // division function

    bool operator==(const Fraction& other) const; // equality function

    void print(); // prints out the fractions

    // helper methods: 
    void reduceFrac();        // reduce function
    int gcd(int a, int b);   // gcd function
    int lcd(int a, int b);  //  lcd function
    int lcm(int a, int b); //   lcm function

};

#endif //ending the header file



