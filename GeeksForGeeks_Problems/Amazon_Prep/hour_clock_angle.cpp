// https://www.geeksforgeeks.org/calculate-angle-hour-hand-minute-hand/
//
// Input : 12, 30
// Output : 165
//
//

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int calcAngle(int h, int m)
{
	if ((h > 12) || (h < 1) || (m > 60) || (m < 1))
		return -1;
	
	if (h == 12)
		h = 0;
	if (m == 60)
		m = 0;
	
	double hour_factor = 0.5;
	double min_factor = 6;
	double angle_hour = (h * 60 + m) * hour_factor;
	double angle_min = m * min_factor;
	int abs_angle = abs(angle_min - angle_hour);
	return min(360 - abs_angle, abs_angle);
}

int main()  
{  
	cout << calcAngle(12, 30) << endl;  
    cout << calcAngle(9, 60) << endl;  
    cout << calcAngle(3, 30) << endl;  
    return 0;  
}  
