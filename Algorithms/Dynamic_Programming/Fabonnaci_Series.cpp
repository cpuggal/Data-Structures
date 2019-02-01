#include<iostream>
#include<stdlib.h>
#include<stdio.h>

#define MAX     10000

using namespace std;

int a[MAX];

int calFab(int s)
{
    if (a[s] != -1)
        return a[s];

    if (s == 0)
        return 0;

    a[s] = s + calFab(s-1);

    return a[s];
}
void init()
{
    int i = 0;

    for(i=0; i<MAX; i++)
        a[i] = -1;
}

int main()
{
    cout<<"***** Welcome to Fabonnaci series via DP *****"<<endl;
    
    init();

    int start = 10;
    int i;
    for(i=start; i>=0; i--)
    {
        cout<<calFab(i)<<endl;
    }
    return 0;
}




