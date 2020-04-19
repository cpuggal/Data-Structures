// https://www.geeksforgeeks.org/a-boolean-matrix-question/

#include <bits/stdc++.h>
using namespace std;


const int R = 3;
const int C = 4;
void modifyMatrix(int Mat[R][C])
{
	bool row_flag = false;
	bool col_flag = false;

	int i = 0, j = 0;

	for (i = 0; i < R; i ++) // Setting first row/col and flags
	{
		for (j = 0; j < C; j++)
		{
			if ((i == 0) && (Mat[i][j] == 1))
				row_flag = true;

			if ((j == 0) && (Mat[i][j] == 1))
				col_flag = true;

			if (Mat[i][j] == 1)
			{
				Mat[i][0] = 1;
				Mat[0][j] = 1;
			}
		}
	}

	for (i = 1; i < R; i++)
	{
		for (j = 1; j < C; j++)
		{
			if ((Mat[0][j] == 1) || (Mat[i][0] == 1)) // If row/col is set then set this
				Mat[i][j] = 1;
		}
	}

	if (col_flag == true)
	{
		for (i = 0; i < R; i++)
			Mat[i][0] = true;
	}

	if (row_flag == true)
		for (j = 0; j < C; j++)
			Mat[0][j] = true;

}

void printMatrix(int Mat[R][C])
{
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cout << Mat[i][j] << " ";
		}
		cout << endl;
	}
}

int main() {
	// your code goes here


	int mat[R][C] = { { 1, 0, 0, 1 },
                      { 0, 0, 1, 0 },
                      { 0, 0, 0, 0 } };

    cout << "Input Matrix :\n";
    printMatrix(mat);

    modifyMatrix(mat);

    cout << "Matrix After Modification :\n";
    printMatrix(mat);

	return 0;
}
