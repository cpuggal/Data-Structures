#include <stdio.h>
#include "/Users/chandan.p/Documents/Chandan/Chandan-Git/stdc++.h"

using namespace std;

bool isACombination(int a[], int b[], int size)
{
    std:unordered_map<int,bool> map;
    
    int i = 0;

    while(i<size)
    {
	map[a[i]] = true;
        i++;
    }

    i = 0;
    
    while(i<size)
    {
        if(map[b[i]] == true)
        {
	        auto it = map.find(b[i]);
	        map.erase(it);
        }
	i++;
    }

    if (map.size() == 0)
        return true;
    else
	    return false;
}

int main()
{
    int nuts[] = {2,5,12,22,48};
    int bolts[] = {12,5,48,2,22};


    if(isACombination(nuts, bolts, sizeof(nuts)/sizeof(int)))
	    cout<<"Its a correct match\n";
    else
        cout<<"Match failed!\n";

    return 0;
}
