//
// Created by 顾浩 on 7/2/18.
//

#ifndef BIGINT_BIGINT_HPP
#define BIGINT_BIGINT_HPP

#include <string>
#include <vector>

using namespace std;

//class string;   //why needed
//class vector;

class BigInt {
public:
    BigInt()=default;
    BigInt(const BigInt &bi);
    explicit BigInt(const string &s);   // how to declare

    //convert string to vector<unsigned int>
    void StrToVec(const string &s, vector<unsigned int> &v);
    void VecToStr(const vector<unsigned int> &v, string &s);

    //override +
    BigInt operator+(const BigInt &);
    //override +=
    BigInt &operator+=(const BigInt &);
    //override =
    BigInt &operator=(const BigInt &);

    //sum
    vector<unsigned int> add(vector<unsigned int> &v1, vector<unsigned int> &v2);

    //get string
    string get_string();


private:
    string _a;  //how to declare as const string
};

#endif //BIGINT_BIGINT_HPP
