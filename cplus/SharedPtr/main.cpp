//
//  main.cpp
//  SharedPtr
//
//  Created by 顾浩 on 24/2/18.
//  Copyright © 2018 顾浩. All rights reserved.
//

#include <iostream>
#include <string>
#include "SharedPtr.hpp"

using namespace std;

int main()
{
    SharedPtr<string> pstr(new string("abc"));
    SharedPtr<string> pstr2(pstr);
    SharedPtr<string> pstr3(new string("hao"));
    pstr3 = pstr2;
    
    return 0;
}
