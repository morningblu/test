#include <iostream>
#include <string>
#include <vector>

#include "BigInt.hpp"

using namespace std;

int main(int argc, char *argv[])
{
    if (argc != 3) {
        cout<<"Invalid input"<<endl;
        return 1;
    }

    string str1 = argv[1], str2 = argv[2];
    BigInt a(str1),b(str2);
    BigInt sum = a+b;
    cout<<sum.get_string()<<endl;
    return 0;
}