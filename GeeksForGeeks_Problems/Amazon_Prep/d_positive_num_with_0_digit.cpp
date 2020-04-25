// https://www.geeksforgeeks.org/count-d-digit-positive-integers-with-0-as-a-digit/
//
//

#include <iostream>
#include <bits/stdc++.h>
#include <typeinfo>

using namespace std;

int findCount(int d)
{
	int AllNumbersOf_d_Digits = 9 * pow(10, d-1);
	int AllNonZeroNumbersOf_d_Digits = pow(9, d);
//	cout << "All: " << AllNumbersOf_d_Digits << " NonZero : " << AllNonZeroNumbersOf_d_Digits << endl;

	return AllNumbersOf_d_Digits - AllNonZeroNumbersOf_d_Digits;
}

int main()
{
    int d = 1;
    cout << "d : " << d << " have numbers: " << findCount(d) << endl;

    d = 2;
    cout << "d : " << d << " have numbers: " << findCount(d) << endl;

    d = 4;
    cout << "d : " << d << " have numbers: " << findCount(d) << endl;
    return 0;
}
