// Geeksforgeeks : https://www.geeksforgeeks.org/check-given-four-points-form-square/
// How to check if given four points form a square


#include<iostream>
#include "/Users/chandan.p/Documents/Chandan/Chandan-Git/stdc++.h"

using namespace std;

typedef struct point
{
    int x, y;
}Point;


// Gives square of distance between two points
int distanceSquare(Point p1, Point p2)
{
    int d1 = p1.x - p2.x;
    int d2 = p1.y - p2.y;
    return d1*d1 + d2*d2;
}

// Returns true if square, else false
bool isSquare(Point p1, Point p2, Point p3, Point p4)
{
    int d1 = distanceSquare(p1, p2);
    int d2 = distanceSquare(p1, p3);
    int d3 = distanceSquare(p1, p4);

    cout << "d1: " << d1 << " d2: " << d2 << " d3: " << d3 << endl;

    if ((d1 == d2) && (2 * d1 == d3) && (2 * distanceSquare(p2, p4) == distanceSquare(p2, p3)))
    {
        cout << "Condition 1" << endl;        
        return true;
    }

    if ((d1 == d3) && (2 * d1 == d2) && (2 * distanceSquare(p2, p3) == distanceSquare(p2, p4)))
    {
        cout << "Condition 2" << endl;
        return true;    
    }

    if ((d2 == d3) && (2 * d2 == d1) && (2 * distanceSquare(p3, p2) == distanceSquare(p3, p4)))
    {
        cout << "Condition 3" << endl;
        return true;
    }

    return false;
}


// Returns true if rectangle, else false
bool isRectangle(Point p1, Point p2, Point p3, Point p4)
{
    Point arr[4] = {p1,p2,p3,p4};
    int i = 0, j = 0;

    set<int> distance;

    for (i = 0; i < 4; i++)
    {
        for(j = 0; j < 4; j++)
        {
            if (i != j)
               distance.insert(distanceSquare(arr[i],arr[j]));
        }
    }
    
    if (distance.size() > 3) // If we have more than 3 distances then its not a rectable anyway
        return false;

    if (distance.size() == 2)
    {
        cout << "Rectangle is a Square!" << endl;
        return true;
    }

    if (distance.size() == 3)
        return true;
    else
        return false;
}

int main()
{
    cout<<"***** Welcome to Square Checker  *****"<<endl;
    Point p1 = { 20, 10 }, p2 = { 10, 20 },
          p3 = { 20, 20 }, p4 = { 10, 10 };

   isSquare(p1, p2, p3, p4) ? cout << "Yes, its Square" << endl : cout << "Not a square" << endl;
   cout << endl;
   isRectangle(p1, p2, p3, p4) ? cout << "Yes, its Rectangle" << endl : cout << "Not a Rectangle" << endl;   
   return 0;
} 


