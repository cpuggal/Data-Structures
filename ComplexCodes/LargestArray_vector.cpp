/**
 * https://www.interviewbit.com/problems/largest-number/
 * @input A : Integer array
 * @input n1 : Integer array's ( A ) length
 *
 * @Output Integer array. You need to malloc memory, and fill the length in len1
 */

#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<cmath>
#include <vector> 


using namespace std;

bool compareFun(string a, string b)
{
    string x = a.append(b);
    string y = b.append(a);

    return x.compare(y) > 0 ? 1:0;
}

string largestNumber(const vector<int> &A)
{
    vector<string> res;
    string ans;

    int i = 0;
    
    for (i=0; i<A.size(); i++)
        res.push_back(to_string(A[i]));
                  
    sort(res.begin(), res.end(), compareFun);
    /*
    for (auto j = res.begin(); j!=res.end(); j++)
    {
        cout<<stoi(*j)<<" ";;
    }*/
    
    for(i=0;i<res.size();i++)
    {
        ans+=res[i];
    }
    return ans;

}

int main()
{
    cout<<"***** Welcome to Largest number *****"<<endl;
    
    vector<int> g1; 
  
    for (int i = 10; i <= 15; i++) 
        g1.push_back(i); 
    
    cout<<"Answer is "<<largestNumber(g1)<<endl;

}
