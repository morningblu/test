//
// Created by 顾浩 on 7/2/18.
//

#include "BigInt.hpp"


BigInt::BigInt(const BigInt &other):_a(other._a) {}

BigInt::BigInt(const string &s):_a(s) {}

BigInt BigInt::operator+(const BigInt &b)
{
    BigInt newBi;
    vector<unsigned int> v1, v2, sum;

    //string1 to vector<int>
    BigInt::StrToVec(_a, v1);
    reverse(v1.begin(), v1.end());

    //string2 to vector<int>
    BigInt::StrToVec(b._a, v2);
    reverse(v2.begin(), v2.end());

    sum = BigInt::add(v1, v2);
    reverse(sum.begin(), sum.end());

    //vector<int> to string
    BigInt::VecToStr(sum, newBi._a);

    return newBi;   //is there any problem?
}

BigInt &BigInt::operator+=(const BigInt &b)
{
    vector<unsigned int> v1, v2;
    BigInt::StrToVec(_a, v1);
    BigInt::StrToVec(b._a, v2);
    BigInt::VecToStr(BigInt::add(v1, v2), _a);

    return *this;
}

BigInt &BigInt::operator=(const BigInt &other)
{
    if (this == &other) return *this;

    _a = other._a;
    return *this;
}

void BigInt::StrToVec(const string &s, vector<unsigned int> &v)
{
    for (unsigned int i=0; i<s.length(); i++)
        v.push_back(s[i]-'0');
}

void BigInt::VecToStr(const vector<unsigned int> &v, string &s)
{
    s.clear();  //clean the string
    for (vector<unsigned int>::const_iterator it=v.begin(); it!=v.end(); it++) {
        s.push_back(*it + '0');
    }
}

vector<unsigned int> BigInt::add(vector<unsigned int> &v1, vector<unsigned int> &v2)
{
    vector<unsigned int> v;
    size_t len = max(v1.size(),v2.size());
    unsigned int outCarry = 0; //前进位
    v.reserve(len+1);

    for(size_t i=0; i<len; i++) {
        unsigned int elem1 = i<v1.size()?v1[i]:0u;
        unsigned int elem2 = i<v2.size()?v2[i]:0u;
        v.push_back((elem1+elem2+outCarry)%10);
        outCarry = (elem1+elem2+outCarry)/10;
    }
    if (outCarry)
        v.push_back(outCarry);

    return v;
}

string BigInt::get_string()
{
    return _a;
}



