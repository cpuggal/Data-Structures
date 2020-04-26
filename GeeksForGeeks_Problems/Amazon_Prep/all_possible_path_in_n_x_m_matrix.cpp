// https://www.geeksforgeeks.org/print-all-possible-paths-from-top-left-to-bottom-right-of-a-mxn-matrix/
// https://www.geeksforgeeks.org/count-possible-paths-top-left-bottom-right-nxm-matrix/
// Input : { {1, 2, 3}, {4, 5, 6} }
// Output : 3
//

#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define DEBUG			0
#define FULL_PATH		0
#define PATH_COUNT		1

string path = "";
int counter = 0;

void printAllPaths_rec(int mar[][3], int n, int m, int i, int j)
{
	if ((i == n -1) && (j == m -1))	//end 
	{
		if (FULL_PATH)
			cout << path << " " << mar[i][j] << endl;
		if (PATH_COUNT)
			counter ++;
		return;
	}
	
	if ((i == n) || (j == m)) // out of bound
		return;

	char c = mar[i][j] + '0';
	int len1 = path.length();
	
	if (DEBUG)
		cout << "path: " << path << " i: " << i << " j :" << j << endl;
		
	path.push_back(' '); // Add space
	path.push_back(c); // Add Char
	int len2 = path.length();
	
	printAllPaths_rec(mar, n, m, i + 1, j); //down
	printAllPaths_rec(mar, n, m, i, j + 1); //right
	
	path = path.substr(0, len1); //Remove Char and Space
}

void printAllPaths(int mar[][3], int n, int m)
{
	printAllPaths_rec(mar, n, m, 0, 0);
	if (PATH_COUNT)
		cout << "Count is : " << counter << endl;
}

int numberOfPaths(int n, int m)
{
	if ((n == 1) && (m == 1))
		return 1;

	if ((n == 0) || (m == 0))
		return 0;

	return numberOfPaths(n - 1, m) + numberOfPaths(n, m - 1);
}

int main() 
{ 
    int mat[2][3] = { {1, 2, 3}, {4, 5, 6} }; 
    printAllPaths(mat, 2, 3); 
    cout << numberOfPaths(2, 3) << endl;
    cout << numberOfPaths(3, 3) << endl;
    return 0; 
} 