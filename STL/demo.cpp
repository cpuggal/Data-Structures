#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include "/Users/chandan.p/Documents/Chandan/Chandan-Git/stdc++.h"

#define VECTOR              0
#define SET                 0
#define MAP                 0
#define RANGE_QUEST         0
#define MY_DS               0
#define MAP_VECTOR          1

/*** 
 * Ref: https://www.youtube.com/watch?v=g-1Cn3ccwXY&list=PLfBJlB6T2eOvyt21CIX_PMmhOgWHiFVab
 * Set: https://www.geeksforgeeks.org/seterase-c-stl/
 * Set : http://www.cplusplus.com/reference/set/set/erase/
 * Bounds : https://www.geeksforgeeks.org/upper_bound-and-lower_bound-for-vector-in-cpp-stl/ 
 * Map :
***/
using namespace std;


#if (VECTOR)
void isPresent(vector <int> v, int x)
{
    bool present = binary_search (v.begin(), v.end(), x);

    if (present)
        cout << x << " is present" << endl;
    else
        cout << x << " is absent" << endl;
}

bool descending(int x, int y)
{
    if (x > y)
        return true;
    else
        return false;
}

void addXtoVector(vector <int> *v, int d)
{
    cout << "Vector is incremented with : " << d <<endl;
    for (int &x: *v)
    {
        x+=d;
    }
}

void printVector(vector <int> v)
{   
    cout << "Vector is : ";

    for (auto it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

void printer(vector <int> v)
{
    cout<<"Printer ! Vector " << endl;
    for(int x:v)
    {
        cout << x <<" ";
    }
    cout << endl;
}

void vector_and_search()
{
    vector <int> v = {100, 5, 10, 11, 19};
    vector <int>::iterator it1;
    vector <int>::iterator it2;

//    cout << v[2] << endl;
    cout << "Sorting Vector" << endl;
    sort (v.begin(), v.end());
       
    printVector(v);
    
    int x = 5;
    
    isPresent(v, x);

    isPresent(v, 9);

    cout << "Pushing 9 into Vector three times" << endl;
    v.push_back(9);
    v.push_back(9);
    v.push_back(9);

    isPresent(v, 9);

    cout << "Sorting Vector" << endl;
    
    sort (v.begin(), v.end());
    isPresent(v, 9);   

    x = 9;
    it1 = lower_bound (v.begin(), v.end(), 9);
    cout << "lower bound of "<< x << " is "<< *it1 << endl;

    x = 9;
    it2 = upper_bound(v.begin(), v.end(), x);
    cout << "Upper bound of "<< x << " is "<< *it2 << endl;
    
    cout << x << " is appering " << it2 - it1 << " times" << endl; 
    x = 8;
    it1 = lower_bound(v.begin(), v.end(), x);
    cout << "lower bound of "<< x << " is "<< *it1 << endl;

    printVector(v);

    sort(v.begin(), v.end(), descending);
    cout << "Descending Order " ;
    printVector(v);
    printer(v);

    addXtoVector(&v, 5);
    printer(v);

    cout << endl;
}
#endif

#if (SET)

void printSet(set <int> s)
{
    for(int x: s)
        cout << x <<" ";

    cout << endl;
}

void printSetIterator(set <int>::iterator it, set <int> s, int x)
{
    if(it == s.end())
        cout << x << " is not Present in Set" << endl;
    else
        cout << x << " is Present in Set" << endl;

}    
void set_and_search()
{
    set <int> s;
    int x;

    s.insert(100);
    s.insert(-1);
    s.insert(50);
    s.insert(-100);

    printSet(s);

    x = -1;
    auto it = s.find(x);
    
    cout << "Searching for elements in Set" << endl;

    printSetIterator(it, s, x);

    x = 5;
    it = s.find(x);    
    printSetIterator(it, s, x); 

    cout << "Bounds in Set" << endl;    

    x = -1;
    it = s.lower_bound(x);
    cout << *it << " is lower bound of " << x << endl;

    it = s.upper_bound(x);
    cout << *it << " is upper bound of " << x << endl;    

    x = 0;
    it = s.lower_bound(x);
    cout << *it << " is lower bound of " << x << endl;

    it = s.upper_bound(x);
    cout << *it << " is upper bound of " << x << endl;

    x = 200;
    int res = s.erase(x);
//    cout << res <<endl;
    if(res == 0)
        cout << x << " is not Present in Set" << endl;
    else
        cout << x << " is Present in Set" << endl;

    x = -1;
    res = s.erase(x);
//    cout << res <<endl;
    if(res == 0)
        cout << x << " is not Present in Set" << endl;
    else
        cout << x << " is Present in Set" << endl;
}
#endif

#if (MAP)

void printMap(map <char, int> m)
{
    for (auto it = m.begin(); it != m.end(); it++)
    {
        cout << it->first << "-->" << it->second <<endl;
    }
}

void map_and_search()
{
    map<int, int> m;

    m[1] = 100;
    m[200] = 5;
    m[900] = 1;

    map<char, int> cnt;
    string name = "chandan puggal";

    for (char c : name)
    {
        cnt[c]++;
    }
    printMap(cnt);


}
#endif


#if (RANGE_QUEST)
void range_algo()
{
    set <pair <int, int>> s;

    s.insert({100, 200});
    s.insert({20, 30});
    s.insert({2,3});
    s.insert({400, 450});

    int point = 500;

    pair <int, int> p = {point, INT_MAX};

    for (pair <int, int> p : s)
    {
        cout << p.first << ", " << p.second << endl;
    }

    auto it = s.upper_bound(p);

    if (it == s.begin())
    {
        cout << "The value " << point << " doesn't exisit in this Set" << endl;
    }
    else
    {
        it --;

        if ((it->first <= point) && (it->second >= point))
            cout << "The value " << point << " exist in this Set" << endl;
        else
            cout << "The value " << point << " doesn't exisit in this Set" << endl;
    }
}

#endif

#if (MY_DS)

void printV(vector < pair<char, int>> v)
{
    for (auto it: v)
    {
        cout << it.first << "-->" << it.second << endl;
    }
    cout<<endl;
}

bool vector_sorter(pair<char, int> a, pair<char, int> b)
{
    int p1 = a.first;
    int p2 = b.first;
    if (p1 > p2)
        return false;
    else
        return true;
}
void my_ds()
{
    vector < pair<char, int>> v;
    
    pair <int, int> p;

    v.push_back(make_pair('b', 30));
    v.push_back(make_pair('c', 130));
    v.push_back(make_pair('a', 320));
    v.push_back(make_pair('e', 4330));
    v.push_back(make_pair('d', 300));
    v.push_back(make_pair('f', 240));

//    mp['h']=make_pair(22, 50);
//    mp['a']=make_pair(25, 50);
//    mp['n']=make_pair(20, 40);
//    mp['d']=make_pair(32, 90);

    printV(v);

    sort(v.begin(), v.end(), vector_sorter);
    
    cout << "After Sorting!" << endl;
    printV(v);
}
#endif

#if (MAP_VECTOR)

void printMapOfVectors(map <string, vector<int>> myMap)
{
    int i = 0;
    for (auto it : myMap)
    {
        cout << it.first << " --> ";
        vector <int> v = it.second;
        while(i !=  v.size())
        {
            cout << v[i] << " ";
            i++;
        }
        i = 0;
        cout << endl;
    }
}

void mapOfVectors()
{
    cout<< "mapOfVectors" << endl;
    map <string, vector <int>> m;
    string str;
    int number = 5;
    int n = 0;
//    auto it = m.find(0);
   
    cout << "Enter number " << endl;
   cin >> number; 
    while(number != 0)
    {
        cout << "Enter the Map Index" << endl;
        cin >> str;
        
        auto it = m.find(str);
        if (it == m.end())
        {
            vector <int> v;
            while (n >= 0)
            {
                cout << "Enter vector number for String" << endl;
                cin >> n;
                if (n >=0)
                    v.push_back(n);
            }
            m[str] = v;
            n = 0;
            number --;
        }
        else
            cout << "Already Present" << endl;;
    }

    printMapOfVectors(m);
}
#endif

int main()
{
    cout<<"***** Welcome to STL Tutorial! *****"<<endl;

#if (VECTOR)
    vector_and_search();
#endif

#if (SET)
    set_and_search();
#endif

#if (MAP)
    map_and_search();
#endif

#if (RANGE_QUEST)
    range_algo();
#endif

#if (MY_DS)
    my_ds();
#endif    

#if (MAP_VECTOR)    
    mapOfVectors();
#endif    
    return 0;
}
