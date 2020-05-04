// https://www.geeksforgeeks.org/check-if-a-given-sequence-of-moves-for-a-robot-is-circular-or-not/
// 
//

#include <iostream>
#include<bits/stdc++.h>

#define DEBUG		0	
#define fo(i,n)		for(i = 0; i < n; i++)
#define NORTH		0
#define EAST		1
#define SOUTH		2
#define WEST		3
#define DEFAULT		0
using namespace std;


bool isCircular(string str)
{
	if(str.length() == 0)
		return true;
	
	int i;
	int dir = NORTH;
	char ch;
	int x = DEFAULT, y = DEFAULT;
	
	fo(i,str.length())
	{
		ch = str[i];
		
		if(ch == 'L')
			dir = (dir + 3) % 4;
		else if(ch == 'R')
			dir = (dir + 1) % 4;
		else // move (G)
		{
			if(dir == NORTH)
				y++;
			else if(dir == EAST)
				x++;
			else if(dir == SOUTH)
				y--;
			else
				x--;
		}
	}
	
	if((x == DEFAULT) && (y == DEFAULT))
		return true;
	else
		return false;
}


int main() 
{ 
    char path[] = "GLGLGLG"; 
    if (isCircular(path)) 
      cout << "Given sequence of moves is circular" << endl; 
    else
      cout << "Given sequence of moves is NOT circular" << endl; 
      
    if (isCircular("GLGLRG")) 
      cout << "Given sequence of moves is circular" << endl; 
    else
      cout << "Given sequence of moves is NOT circular" << endl;
}
