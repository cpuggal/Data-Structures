/* Read input from STDIN. Print your output to STDOUT*/
#include<stdio.h>
#define MAX     1000

void printarr(int arr[], int N)
{
    int i;
    for (i=0;i<N;i++)
        printf("%d ",arr[i]);

    printf("\n");
}


int main(int argc, char *a[])
{
	//Write code herei
    int T, N, V[MAX], P[MAX];
    int i,j;
    int flag = 0;
    int Bal;
    scanf("%d", &T);
    while(T!=0)
    {
        scanf("%d", &N);
        i=0;
        flag = 0;
        Bal = 0;
        while(i != N)
        {
            scanf("%d",&V[i]);
            i++;
        }

  //      printarr(V,N);
        
        i=0;
        while(i != N)
        {
            scanf("%d",&P[i]);
            i++;
        }

//        printarr(P,N);

        for (i=0;i<N;i++)
        {
            Bal = Bal +  P[i] - V[i];
            if (Bal < 0)
            {
                printf("LOSE\n");
                flag = 1;
                break;
            }
        }
        if (flag == 0)
            printf("WIN\n");
    T--;
    }
}

