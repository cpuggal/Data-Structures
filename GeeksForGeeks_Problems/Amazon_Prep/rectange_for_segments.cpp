// https://www.geeksforgeeks.org/check-four-segments-form-rectangle/

// C++ program to check if a given tree is BST.
#include <bits/stdc++.h>
using namespace std;

struct Segment {
	int ax, ay;
	int bx, by;
};

int dist_square(pair<int,int> p1, pair<int,int> p2)
{
	int x_diff = p1.first - p2.first;
	int y_diff = p1.second - p2.second;
	return x_diff * x_diff + y_diff * y_diff;
}

bool isPossibleRectangle(Segment segments[], int N)
{
	set<pair<int,int>> myset;

	for (int i = 0; i < N; i ++)
	{
		myset.insert(make_pair(segments[i].ax, segments[i].ay));
		myset.insert(make_pair(segments[i].bx, segments[i].by));
	}

	if (myset.size() != 4)
		return false;

	set <int> distances;

	for (auto it1 = myset.begin(); it1 != myset.end(); it1 ++)
	{
		for (auto it2 = myset.begin(); it2 != myset.end(); it2 ++)
		{
			if (*it1 != * it2)
				distances.insert(dist_square(*it1, *it2));
		}
	}

	if ((distances.size() > 3) || (distances.size() <= 1))
		return false;

	int dis_arry[3];
	int i = 0;

	for (auto it1 = distances.begin(); it1 != distances.end(); it1 ++)
	{
		dis_arry[i] = *it1;
		i++;
	}

	if (distances.size() == 2) // Square has two distances only
	{
		return (2 * dis_arry[0] == dis_arry[1]);
	}
	else // Possible rectangle with 3 sides.
		return ((dis_arry[0] + dis_arry[1]) == dis_arry[2]);
}


/* Driver program to test above functions*/
int main()
{
	Segment segments[] =
    {
        {4, 2, 7, 5},
        {2, 4, 4, 2},
        {2, 4, 5, 7},
        {5, 7, 7, 5}
    };

    (isPossibleRectangle(segments, 4))?cout << "Yes\n":cout << "No\n";

	return 0;
}

