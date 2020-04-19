// Geeksforgeeks : https://www.geeksforgeeks.org/position-of-rightmost-set-bit/
// Write a one line function to return position of first 1 from right to left, in binary representation of an Integer.

// I/P    18,   Binary Representation 010010
// O/P   2
// I/P    19,   Binary Representation 010011
// O/P   1

#include<iostream>
#include "/Users/chandan.p/Documents/Chandan/Chandan-Git/stdc++.h"

using namespace std;

int bitWiseComplement(int n)
{
   // if (n % 2 == 0)
   //     return log2(n & -n);
   //else
        return (log2(n & -n) + 1);
}

int ffs_use(int n)
{
    return ffs(n);    
}

int leftshift_use(int n)
{
    int pos = 1;
    int m = 1;

    while(!(n & m))
    {
        m = m << 1;
        pos++;
    }
    return pos;
}

int xor_use(int n)
{
    return log2(n ^ (n - 1)) + 1;
}
int main()
{
    int n = 4;
    cout << "bitWiseComplement first set bit: " << bitWiseComplement(n) << endl; 
    cout << "ffs_use first set bit: " << ffs_use(n) << endl;
    cout << "leftshift_use first set bit: " << leftshift_use(n) << endl;
    cout << "xor_use first set bit: " << xor_use(n) << endl;
    return 0;
}
