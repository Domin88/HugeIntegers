#pragma once
//headerfile (HugeInteger.h)

#ifndef HUGEINTEGER_H 
#define HUGEINTEGER_H

#include<iostream> 
#include<array> 
#include<string> 
#include<cmath>
#include <climits>
using namespace std;

class HugeInteger
{
public:
    HugeInteger(unsigned long long = 0);
    HugeInteger(const string&);
    void output()const;
    void input(const string&);
    HugeInteger add(const HugeInteger&) const;
    HugeInteger add(unsigned long long int) const;
    HugeInteger add(const string&) const;
    HugeInteger subtract(const HugeInteger&) const;
    HugeInteger subtract(unsigned long long int) const;
    HugeInteger subtract(const string&) const;

private:
    array <  long long, 60 > integer;
};

#endif