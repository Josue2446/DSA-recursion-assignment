/*
FILE: wk7_recursion_assignment_Josue.cpp

Summary: Driver file to test function that are done with
         recursion. Declared/Defined below.

Test Cases: N/A

Author: Josue Lopez

Date: 05/23/2023

Summary of modifications: N/A 

Complier: Ubuntu (g++)

void print(const int& val):
    - called inside the print_pattern function recursively
      takes in value for amount of stars to print

void print_pattern(const int& val):
    - takes input value and prints that amout of starts in pattern

const int duplicate_values(const string& str, const char& ch, int cell):
    - counts the occurances of a character in a given string. Output
      is returned as an integar.

const bool koalas(int val):
    - input value in evaluated and if value ends up being 42, you
      win the game.
    rules:
        1 - if val is even, then you may give back exactly val / 2 koalas
        2 - if val is divisible by 3 or 4, then you may multiply the last
            two digits of val and give back this many koalas
        3 - if val is divisible by 5, then you may give back 
            exactly 42 koalas
*/

#include <iostream> // cout, endl
#include <string> // string

using std::endl;
using std::cout;
using std::string;

void print(const int& val);
void print_pattern(const int& val);
const int duplicate_values(const string& str, const char& ch, int cell);
const bool koalas(int val);

int main(){

    print_pattern(4);
    cout << endl;
    cout << duplicate_values("how many h's are there?", 'h', 0); // 3
    cout << endl << endl;

    cout << "koalas(250): " << koalas(250) << endl; // true
    cout << "koalas(42): " << koalas(42) << endl; // true
    cout << "koalas(84): " << koalas(84) << endl; // true
    cout << "koalas(53): " << koalas(53) << endl; // false
    cout << "koalas(41): " << koalas(41) << endl; // false

    cout << endl;
    return 0;
}

void print(const int& val){
    for(int i = 0; i < val; i++)
        cout << "*";
    cout << endl;
    return;
}

void print_pattern(const int& val){
    for(int i = val; i > 0; i--)
        print(i);
    for(int i = 1; i <= val; i++)
        print(i);
    return;
}

const int duplicate_values(const string& str, const char& ch, int cell){
    if(cell >= str.size())
        return 0;
    else if(str[cell] == ch)
        return 1 + duplicate_values(str, ch, cell + 1);
    else
        return duplicate_values(str, ch, cell + 1);
}

const bool koalas(int val){
    if(val == 42)
        return true; // you won

    if(val < 42)
        return false;

    if((val % 2) == 0 && koalas(val / 2))
        return true;

    if((val % 5) == 0 && koalas(val - 42))
        return true;

    if((val % 4) == 0 || (val % 3) == 0)
        return koalas(val - ( (val % 10) * ((val % 100) / 10) ));

    return false;
}
