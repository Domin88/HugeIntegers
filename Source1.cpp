//Tester file
#include<iostream>
#include<string>
#include<array>
#include <cmath>
#include "Header.h"

using namespace std;

int main(int argc, char* argv[])
{
    HugeInteger num1(9999999999999090000);
    HugeInteger num2(9999999999999990000);
    HugeInteger num3 = num1.add(num2);
    
    HugeInteger num4 = num2.subtract(num1);
   

    cout << "num1 =";
    num1.output();
    cout << endl;

    cout << "num2 =";
    num2.output();

    cout << endl;

    cout << "num1 + num2 = ";
    num3.output();
    cout << endl;

    cout << "num2 - num1 = ";
    num4.output();

   

    cout << endl;



    return 0;
}
