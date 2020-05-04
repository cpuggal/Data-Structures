// https://www.geeksforgeeks.org/the-knights-tour-problem-backtracking-1/
// Input : 
// Output : 
//

#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define DEBUG	0
#define N		8

// TLE with below movements
//int row[N] = {2, -2, 2, -2, 1, 1, -1, -1};
//int col[N] = {1, 1, -1, -1, 2, -2, 2, -2};
	
 int row[N] = {  2, 1, -1, -2, -2, -1,  1,  2 }; 
 int col[N] = {  1, 2,  2,  1, -1, -2, -2, -1 }; 
void printArr(int arr[][N])
{
	int i, j;
	for(i = 0; i < N; i++)
	{
		for(j = 0; j < N; j++)
		{
			cout<< arr[i][j] << " ";
		}
		cout << endl;
	}
}

bool isSafe(int i, int j)
{
	if ((i >= 0) && (j >= 0) && (i < 8) && (j < 8))
		return true;
	else
		return false;
}

bool solveKT_recu(int arr[][N], int curr_row, int curr_col, bool visited[][N], int step)
{
	if (N*N == step)
		return true;
		
	int i, r, c;
	
	
	for(i = 0; i < N; i++)
	{
		r = curr_row + row[i];
		c = curr_col + col[i];
		
		if(isSafe(r,c) && (visited[r][c] == false))
		{
			arr[r][c] = step;
			visited[r][c] = true;
			if(solveKT_recu(arr, r, c, visited, step+1))
				return true;
			else
			{
				arr[r][c] = -1;
				visited[r][c] = false;
			}
		}
	}
	return false;
}

void solveKT()
{
	int arr[N][N] = {-1};
	bool visited[N][N] = {false};
	arr[0][0] = 0;
	visited[0][0] = true;
	solveKT_recu(arr, 0, 0, visited, 1);
	
	printArr(arr);
}

int main() 
{ 
    solveKT(); 
    return 0; 
}

