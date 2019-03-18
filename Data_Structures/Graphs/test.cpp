#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include "/Users/chandan.p/Documents/Chandan/Chandan-Git/stdc++.h"

#define MAX         100
#define DEBUG      0

using namespace std;


/*
Name: Chandan  Puggal

Given a set of integers, write three functions that work for the below three scenarios: 
Input Array: (-20, 4, -2, -4, 8, 6, 22, 10, -12)
Function#1. find the pair(s) which gives sum equal to zero ; example output: (-4, 4)
Function#2. find the pair(s) which gives non-zero sum whose distance is closest to 0; example output: (10, -12), (-2, 4), etc 
Function#3. find the pair(s) which gives sum whose distance is farthest from 0
*/

vector<int> SortedVector(int arr[], int size)
{
    vector<int> input;
    
    for (int i = 0;i < size; i++)
        input.push_back(arr[i]);
        
    sort(input.begin(), input.end());
    
    return input;
}

vector<pair<int,int> > function1(int arr[], int size)
{
    vector<pair<int,int> > v;
    map <int, pair<int,int> >m;
    int i = 0;
    int l = 0;
    int r = size -1;
    int sum = 0;
    int prevSum = 0;
    int newSum = 0;
    
    if(size == 0)
    {
        cout<<"Empty input"<<endl;
        return v;
    }
    
    sort(arr, arr+size);
    
    while(l < r)
    {
        sum = arr[l] + arr[r];

        if (sum == 0)
        {
            v.push_back(make_pair(arr[l], arr[r]));
            l ++;
            r --;
        }
        else if(sum < 0)
            l++;
        else
            r--;
    }
    
    return v;
}

vector<pair<int,int> > function3(int arr[], int size)
{
    vector<pair<int,int> > v;
    map <int, pair<int,int> >m;
    int i = size -1;
    int sum = 0;
    int largestSum = 0;

    if(size == 0)
    {
        cout<<"Empty input"<<endl;
        return v;
    }
    
    sort(arr, arr+size);
    
    largestSum = sum = arr[i] + arr[i-1];
    
    if (largestSum == abs(arr[0] + arr[1]))
    {
        v.push_back(make_pair(arr[0], arr[1]));
        v.push_back(make_pair(arr[i], arr[i-1]));
    }
    else if (abs(arr[0] + arr[1]) > largestSum)
    {
        largestSum = abs(arr[0] + arr[1]);
        v.push_back(make_pair(arr[0], arr[1]));
    }
    else
    {
        v.push_back(make_pair(arr[i], arr[i-1]));
    }
#if 0    
    for (i = size -2; i > 1; i-- )
    {
        sum = arr[i] + arr[i-1];
        
        if ((largestSum == sum) && (i != size -1)) 
            v.push_back(make_pair(arr[i], arr[i-1]));
        else
            break;
    }
#endif     
    return v;
}

vector<pair<int,int> > function2(int arr[], int size)
{
    vector<pair<int,int> > v;
    map<int, vector<pair<int,int> > > m;
    int i = 0;
    int l = 0;
    int r = size -1;
    int sum = 0;
    int absSum = 0;
    int prevSum = 0;
    int newSum = 0;
    map<int, vector<pair<int,int> > >::iterator it ; 

    
    if(size == 0)
    {
        cout<<"Empty input"<<endl;
        return v;
    }
   // cout<<"H1"<<endl;
    sort(arr, arr+size);
#if DEBUG
    printArr(arr, size);
#endif
    while(l < r)
    {
        vector<pair<int,int> > temp;
        sum = (arr[l] + arr[r]);
        absSum = abs(arr[l] + arr[r]);
        it = m.find(absSum);
#if DEBUG        
        cout<<"sum "<<sum<<" arr[l] "<<arr[l]<<" arr[r] "<<arr[r]<<endl;
#endif
        if (it != m.end())
        {
#if DEBUG            
            cout<<"m.find() "<<it->first<<endl;
#endif            
            it->second.push_back(make_pair(arr[l], arr[r]));
        }
        else
        {
#if DEBUG            
            cout<<"first element"<<endl;
#endif            
            temp.push_back(make_pair(arr[l], arr[r]));
            m[absSum] = temp;
        }
        
        if(sum <= 0)
            l++;
        else
            r--;
    }

    bool ans = false;

    for (it = m.begin(); it != m.end(); it++)
    {
        if (it->first == 0)
        {
#if DEBUG            
            cout<<"0 sum "<<endl;
#endif            
            continue;
        }
        
        if (ans == false)
        {
#if DEBUG            
            cout<<"Here with it as "<<it->first<<endl;
#endif
            ans = true;
            v = it->second;
        }
        else
        {
            break;
        }
    }
    
    return v;
}


void printVector(vector<pair<int,int> > v)
{
    int i;
    int n = v.size();

    for (i=0; i<n; i++) 
    { 
        cout << v[i].first << " "<< v[i].second << endl; 
    } 
}

void printArr(int arr[], int size)
{
    int i;
    for (i=0; i<size; i++)
    {
        cout <<" "<< arr[i] << " ";
    }
    cout<<endl;
}
int main()
{
    

    int arr[] = {-20, 4, -2, -4, 8, 6, 22, 10, -12};

    int size = sizeof(arr)/sizeof(int);

    vector<pair<int,int> > v ;
    v = function1(arr, size);
    cout<<"Function 1 "<<endl;
    printVector(v);
    cout<<endl;


    v = function2(arr, size);
    cout<<"Function 2"<<endl;
    printVector(v);
    cout<<endl;

    v = function3(arr, size);
    
    cout<<"Function 3"<<endl;
    printVector(v);
    cout<<endl;

    printArr(arr, size);
    return 0;
}
