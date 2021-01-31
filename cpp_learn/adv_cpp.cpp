#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int vol(int i = 10, int j = 1, int k = 5){
    return i * j * k;
}

int main()
{
    cout << time(0) << endl;
    srand(time(0));
    cout << time(0) << endl;
    for(int i = 0; i < 10; i ++)
        cout << rand() % 6 + 1<< endl;
    cout << "Vol is : " << vol(1) << endl;
    return 0;
}
