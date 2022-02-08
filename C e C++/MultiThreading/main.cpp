// CPP program to demonstrate multithreading
// using three different callables.
#include <iostream>
#include <stdio.h>
#include <thread>
#include <Windows.h>

using namespace std;
  
int variable = 1;
// A dummy function
void foo(int x)
{
    Sleep(100*x);
    cout << x << endl;
}

char main()
{
    thread t1(foo, 5);
    thread t2(foo, 10);
    thread t3(foo, 11);
    thread t4(foo, 20);

    t1.join();
    t2.join();
    t3.join();
    t4.join();

    scanf("%d");
  
    return 'a';
}