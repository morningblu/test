#include <iostream>
#include <vector>
#include <condition_variable>
#include <thread>

std::mutex m;
std::condition_variable c;
int flag= 0;

void printABC(char ch)
{
    for(int i=0; i<10; i++) {
        std::unique_lock<std::mutex> lock(m);
        c.wait(lock, [=](){return ch==flag+'A';});
        std::cout<<(char)ch<<std::endl;
        flag = (flag+1)%3;
        c.notify_one();
    }
}

int main()
{
    std::vector<std::thread> threads;
    threads.push_back(std::thread(printABC,'A'));
    threads.push_back(std::thread(printABC,'B'));
    threads.push_back(std::thread(printABC,'C'));

    std::for_each(threads.begin(), threads.end(), std::mem_fn(&std::thread::join));

    return 0;
}