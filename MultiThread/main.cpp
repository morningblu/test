#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include "threadpool.h"
#include <unistd.h>

void fun(std::string s)
{
    std::cout<<s<<std::endl;
}

int main(int argc,char **argv)
{
    netlib::ThreadPool pool(4);
    pool.start();
    while(1)
    {
        pool.push(std::bind(fun,std::string("hello")));
    }
    return 0;
}