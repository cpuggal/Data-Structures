// https://www.geeksforgeeks.org/check-given-four-points-form-square/


// C++ program to check if a given tree is BST.
#include <bits/stdc++.h>
using namespace std;

struct Point {
	int x, y;
};

int dist_square(Point p1, Point p2)
{
	int x_diff = p1.x - p2.x;
	int y_diff = p1.y - p2.y;
	return x_diff * x_diff + y_diff * y_diff;
}

bool isSquare(Point p1, Point p2, Point p3, Point p4)
{
	// consider p1 as ref
	int d1 = dist_square(p1, p2);
	int d2 = dist_square(p1, p3);
	int d3 = dist_square(p1, p4);

	if ((d1 == d2) && (2 * d1 == d3))
	{
		if (dist_square(p4, p2) == dist_square(p4, p3))
			return true;
		else
			return false;
	}

	if ((d3 == d2) && (2 * d3 == d1))
	{
		if (dist_square(p4, p2) == dist_square(p2, p3))
			return true;
		else
			return false;
	}

	if ((d1 == d3) && (2 * d1 == d2))
	{
		if (dist_square(p3, p2) == dist_square(p3, p4))
			return true;
		else
			return false;
	}

	return false;
}


/* Driver program to test above functions*/
int main()
{
	 Point p1 = { 20, 10 }, p2 = { 10, 20 },
          p3 = { 20, 20 }, p4 = { 10, 10 };

    isSquare(p1, p2, p3, p4) ? cout << "Yes" : cout << "No";

	return 0;
}

