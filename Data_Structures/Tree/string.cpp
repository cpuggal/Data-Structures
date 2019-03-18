#include<stdio.h>
#include<stdlib.h>
#define SIZE      100

using namespace std;

int main()
{
    char *str = (char *)malloc(sizeof(char) * SIZE);
    
    int len = 0;
    printf("Enter the String \n");
    scanf("%s",str);

    while (str[len] != '\0')
    {
        len++;
    }
    
    printf("Length of %s is %d\n", str, len);

    return 1;
}
