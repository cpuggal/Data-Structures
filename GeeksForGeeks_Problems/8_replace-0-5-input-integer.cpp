//  https://www.geeksforgeeks.org/replace-0-5-input-integer/
#include <iostream>
#include<bits/stdc++.h>

using namespace std;

int change_num(int num, int x, int y) {
	if (num == x)
		return y;
	int temp, i = 0;
	int new_num = 0;
	
	while(num != 0) {
		temp = num % 10;
		if(temp == x)
			temp = y;
		new_num = temp * pow(10, i) + new_num;
		num = num / 10;
		i++;
	}
	
	return new_num;
}

int main() {
	// your code goes here
	
	cout << change_num(1020, 0, 5) << endl;
	
	return 0;
}
