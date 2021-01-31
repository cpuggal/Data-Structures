#include <bits/stdc++.h>

using namespace std;
#define ARRSIZE     4
#define DEBUG       0

int row_arr[ARRSIZE] = {0, 0, 1, -1};
int col_arr[ARRSIZE] = {1, -1, 0, 0};

int solve_rec(vector<vector<bool> > &visited, int rows, int column, int row_idx, int col_idx)
{
    if ((row_idx < 0) || (col_idx < 0) || (row_idx >= rows) || (col_idx >= column))
        return 0;

    if (visited[row_idx][col_idx] == false)
        visited[row_idx][col_idx] = true;
    else
        return 0;

    int idx;
    int new_row, new_col;

    for(idx = 0; idx < ARRSIZE; idx++)
    {
        new_row = row_idx + row_arr[idx];
        new_col = col_idx + col_arr[idx];
        if ((new_row < 0) || (new_col < 0) || (new_row >= rows) || (new_col >= column))
           continue;     
        else if (visited[new_row][new_col] == false)
        {
            visited[new_row][new_col] = true;
            return 1;
        }
        else
            continue;
    }
    return 1;
}

int solve(int rows, int column)
{
    vector<vector<bool> > visited(rows , vector<bool> (column, false));
    int ans = 0, i, j;
    for(i = 0; i < rows; i++)
    {
        for(j = 0; j < column; j++)
        {
            if (visited[i][j] == false)
                ans += solve_rec(visited, rows, column, i, j);
        }
    }

    return ans;
}
int solve1(int n, int m)
{
    int regular = m/2 * n;
    int special = m % 2;
    int ans;
    if(special == 0)
        return regular;
    else
    {
        int temp = special * n;
        ans = temp/2 + temp % 2 + regular;
        return ans;
    }
}
int main()
{
    int t, n, m;
    int i;
    cin >> t;

    for(i = 0; i < t; i++)
    {
        cin >> n >> m;
        cout << solve1(n, m) << endl;
    }
    return 0;
}
