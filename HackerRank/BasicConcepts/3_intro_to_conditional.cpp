// https://www.hackerrank.com/challenges/30-conditional-statements/problem?h_r=next-challenge&h_v=zen
//
//

#include <bits/stdc++.h>

using namespace std;

void solve(int num)
{
    if ((num % 2 == 1) || ((num % 2 == 0) && ((num >= 6) && (num <= 20))))
    {
        cout << "Weird" << endl;
        return;
    }

    if((num % 2 == 0) && (((num >= 2) && (num <= 5)) || (num > 20)))
    {
        cout << "Not Weird" << endl;
        return;
    }
}

int main()
{
    int N;
    cin >> N;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    solve(N);
    return 0;
}

