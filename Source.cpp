//HugeInterger.cpp (Class implementation file)
#include <iostream>
#include <array>
#include <string>
#include "Header.h"

using namespace std;

HugeInteger::HugeInteger(unsigned long long value)
{
    for ( int i = 0; i < 60; i++)
    {
        integer[i] = 0;
    }
    for ( int j = 59; value != 0 && j >= 0; j--)
    {
        integer[j] = static_cast <unsigned long long>(value % 10);
        value /= 10;
    }
}

HugeInteger::HugeInteger(const string& string)
{
    input(string);
}

void HugeInteger::input(const string& val)
{
    for ( int i = 0; i < 60; i++)
        integer[i] = 0;

    unsigned long long int length = val.size();
    unsigned long long int j;
    unsigned long long int k;

    for (j = 60 - length, k = 0; j < 60; j++, k++)
    {
        if (isdigit(val[k])) //checks to see if it's a digit
            integer[j] = val[k] ;
    }
}

void HugeInteger::output() const
{
    unsigned long long int i;
    for ( i = 0; (integer[i] == 0) && (i < 60); i++)
        ; // skip leading zeroes
    if (i == 60)
        cout << 0;
    else
        for (; i < 60; i++)
            cout << integer[i];
    cout << endl;

}

HugeInteger HugeInteger::add(const HugeInteger& value) const
{
    unsigned long long int carry = 0;
    HugeInteger result;
    for ( long long int i = 59; i >= 0; i--)
    {
        result.integer[i] = integer[i] + value.integer[i] + carry;
        if (integer[i] + value.integer[i] > 9)
        {
            result.integer[i] %= 10;
            carry = 1;
        }
        else
        {
            carry = 0;
        }
    }
    return result;
}

HugeInteger HugeInteger::add(unsigned long long int num) const
{
    return add(HugeInteger(num));
}

HugeInteger HugeInteger::add(const string& str) const
{
    HugeInteger val(str);
    HugeInteger result = this->add(val);
    return result;
}

HugeInteger HugeInteger::subtract(const HugeInteger& value) const
{
    HugeInteger result;
      long long int carry = 0;
    for ( long long int i = 59; i >= 0; i--)
    {
         long long int tempValue = integer[i];
        if (carry == 1)
        {
            tempValue -= 1;
        }
        if (integer[i] >= value.integer[i])
        {
            result.integer[i] = tempValue - value.integer[i];
            carry = 0;
        }
        else
        {
            result.integer[i] = (tempValue ) - value.integer[i];
            carry = 1;
        }
    }
    return result;
}

HugeInteger HugeInteger::subtract(unsigned long long int num) const
{
    return subtract(HugeInteger(num));
}

HugeInteger HugeInteger::subtract(const string& str) const
{
    HugeInteger val(str);
    HugeInteger result = this->subtract(val);

    return result;
}