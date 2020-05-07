// https://www.geeksforgeeks.org/count-number-of-ways-to-cover-a-distance/
//

#include <iostream>
#include<bits/stdc++.h>

#define DEBUG		0	

using namespace std;

int tab[100];

int printCount_DP(int dist)
{
	if (dist < 0)
		return 0;
		
	if(dist == 0)
		return 1;
	
	int i = 0;
	tab[0] = 1;
	tab[1] = 1;
	tab[2] = 2;
	
	for(i = 3; i <= dist; i++)
	{
		tab[i] = tab[i-1] + tab[i-2] + tab[i-3];
	}	
	return tab[dist];
}

int printCountRec(int dist)
{
	if(dist < 0)
		return 0;
	if(dist == 0)
		return 1;
	return printCountRec(dist-1) + printCountRec(dist-2) + printCountRec(dist-3); 
}

int main() 
{ 
    int dist = 4; 
    memset(tab, -1, sizeof(tab));
    cout << printCountRec(dist) << endl; 
    cout << printCount_DP(dist) << endl; 
    
    return 0; 
} 

