#include "heap.h"
#include <iostream>

using namespace std;

int main()
{
    Heap <int> h1(4);
    h1.push(6);
    h1.push(2);
    h1.push(3);
    h1.push(7);
    h1.push(5);
    h1.push(4);
    h1.push(1);

    // h1.push(1);
    // h1.push(6);
    // h1.push(3);
    // h1.push(2);
    // h1.push(5);
    // h1.push(4);

    // h1.push(7);
    // h1.push(4);
    // h1.push(3);
    // h1.push(6);
    // h1.push(5);
    // h1.push(3);
    // h1.push(1);
    // h1.push(2);
    // h1.push(1);
    //cout<<h1.top()<<endl;
    h1.pop();
    //cout<<h1.top()<<endl;
    h1.pop();
    //cout<<h1.top()<<endl;
    h1.pop();
    //cout<<h1.top()<<endl;
    h1.pop();
    //cout<<h1.top()<<endl;
    h1.pop();
   // cout<<h1.top()<<endl;
    h1.pop();
    h1.pop();
    // cout<<h1.top()<<endl;
    // h1.pop();
    // cout<<h1.top()<<endl;
    // h1.pop();
    // cout<<h1.top()<<endl;
    // h1.pop();
    return 0;
}