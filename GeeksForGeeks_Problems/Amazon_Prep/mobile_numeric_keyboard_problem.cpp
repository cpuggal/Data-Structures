// https://www.geeksforgeeks.org/mobile-numeric-keypad-problem/
//
//
//

#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define DEBUG	0

// movement same, up, right, down, left
int row[] = {0, -1, 0, 1, 0};
int col[] = {0, 0, 1, 0, -1};
int getCount_recu(char arr[][3], int i, int j, int num)
{
	if ((arr == NULL) || (num <= 0))
		return 0;
		
	if (num == 1) // only one possible digit left
		return 1;
	
	int move, ro, co, total = 0;
	
	for(move = 0; move < 5; move++)
	{
		ro = i + row[move];
		co = j + col[move];
		
		if ((ro >= 0) && (ro < 4) && (co >= 0) && (co < 3) && (arr[ro][co] != '*') && (arr[ro][co] != '#'))
			total += getCount_recu(arr, ro, co, num - 1);
	}
	return total;
}

int getCount(char arr[][3], int num)
{
	if (num == 0)
		return 0;
	if (num == 1)
		return 10;
	
	int i,j;
	int total = 0;
	
	for(i = 0; i < 4; i++)
	{
		for(j = 0; j <3; j++)
		{
			if ((arr[i][j] != '*') && (arr[i][j] != '#'))
				total += getCount_recu(arr, i, j, num);
		}
	}

	return total;
}

int getCount_dp(char arr[][3], int num)
{
	if ((arr == NULL) || (num <= 0))
		return 0;
		
	if (num == 1) // only one possible digit left
		return 10;
	
	int ro, co, keys = 10;
	int i, j, k, move, number, nextnum;
	int count[keys][num+1];
	
	memset(count, 0, sizeof(count));
	for(i = 0; i < keys; i++)
	{
		count[i][0] = 0;
		count[i][1] = 1;
	}
	
	for(k = 2; k <= num; k++)
	{
		for(i = 0; i < 4; i++)
		{
			for(j = 0; j < 3; j++)
			{
				if ((arr[i][j] != '*') && (arr[i][j] != '#'))
				{
					number = arr[i][j] - '0';
					count[number][k] = 0;
					for(move = 0; move < 5; move++)
					{
						ro = i + row[move];
						co = j + col[move];
						if ((ro >= 0) && (ro < 4) && (co >=0) && (co < 3) && 
						    (arr[ro][co] != '*') && (arr[ro][co] != '#'))
						{
							nextnum = arr[ro][co] - '0';
							count[number][k] += count[nextnum][k-1];
						}
					}
				}
			}
		}
	}
	
	if (DEBUG)
	{
		for(i = 0; i < keys; i++)
		{
			for(k = 0; k <= num; k++)
			{
				cout << count[i][k] << " ";
			}
			cout << endl;
		}
	}
	int answer = 0;
	for(i = 0; i < keys; i++)
		answer += count[i][num];
		
	return answer;
}

int main(int argc, char *argv[]) 
{ 
   char keypad[4][3] = {{'1','2','3'}, 
                        {'4','5','6'}, 
                        {'7','8','9'}, 
                        {'*','0','#'}}; 
   printf("Count for numbers of length %d: %d\n", 1, getCount(keypad, 1)); 
   printf("Count for numbers of length %d: %d\n", 2, getCount(keypad, 2)); 
   printf("Count for numbers of length %d: %d\n", 3, getCount(keypad, 3)); 
   printf("Count for numbers of length %d: %d\n", 4, getCount(keypad, 4)); 
   printf("Count for numbers of length %d: %d\n", 5, getCount(keypad, 5)); 
   
   cout << getCount_dp(keypad, 1) << endl;
   cout << getCount_dp(keypad, 2) << endl;
   cout << getCount_dp(keypad, 3) << endl;   
   cout << getCount_dp(keypad, 4) << endl;
   cout << getCount_dp(keypad, 5) << endl;   
   return 0; 
} 
