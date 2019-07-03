/* Read input from STDIN. Print your output to STDOUT*/
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
#include <algorithm>

#define MAX         10000
using namespace std;

int CalcNumber(int arr[], int n)
{
    int ans = 0;
    int i = 0;

    for (i=0; i<n; i++)
    {
        if(arr[i] > 0)
        {
            ans = ans * 10 + arr[i];
        }
    }
    return ans;
}

void printarr(int arr[], int N)
{
    int i;
    for (i=0;i<N;i++)
        printf("%d ",arr[i]);

    printf("\n");
}

int main(int argc, char *a[])
{
	//Write code here
    int T, N, Even[MAX], Odd[MAX];
    int i,j;
    int S1, S2;
    int N1, N2;
    int e1, o1;
    scanf("%d", &T);
    while(T!=0)
    {
        scanf("%d", &N);
        i=0;
        S1 = S2 = e1 = o1 = 0;
        while(i != N)
        {
            if (i%2 == 0)
            {
                scanf("%d",&Even[e1]);
                if (Even[e1] > 0)
                    S1 = S1 + Even[e1];
                e1++;
            }
            else
            {
                scanf("%d",&Odd[o1]);
                if (Odd[o1] > 0)
                    S2 = S2 + Odd[o1];
                o1++;
            }
            i++;
        }
//        printf("%d %d\n before",S1,S2);

//        printarr(Even,e1);
//        printarr(Odd,o1);

        sort(Even,Even+e1);
        sort(Odd, Odd+o1);
     
//        printarr(Even,e1);
//        printarr(Odd,o1);

        N1 = CalcNumber(Even, e1);
        N2 = CalcNumber(Odd, o1);

//        printf("%d %d\n",N1,N2);
        if (S1 == S2)
        {
           if(N1 > N2) 
              printf("%d\n",N1);
           else
              printf("%d\n",N2);
        }
        else if (S1 > S2)
            printf("%d\n",N1);
        else
            printf("%d\n",N2);

    T--;
    }
}

