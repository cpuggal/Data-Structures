// https://www.hackerrank.com/challenges/30-operators/problem
//
//
//
#include <bits/stdc++.h>

using namespace std;
#define DEBUG		0
// Complete the solve function below.
void solve(double meal_cost, int tip_percent, int tax_percent) {
    
    if(DEBUG)
    {
    	double tp = (double)(tax_percent)/100;
	    double ti = (double)(tip_percent)/100;
	    cout << fixed << setprecision(3);
		cout << tp << endl;
		cout << ti << endl;
    }
		
    double tax = meal_cost * (double)(tax_percent)/100;
    double tip = meal_cost * (double)(tip_percent)/100;
    
    if(DEBUG)
    {
    	cout << fixed << setprecision(3);
		cout << tax << endl;
		cout << tip << endl;
    }
    
    double res = meal_cost + tax + tip;
    cout << round(res) << endl;
}

int main()
{
    double meal_cost;
    cin >> meal_cost;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int tip_percent;
    cin >> tip_percent;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int tax_percent;
    cin >> tax_percent;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    solve(meal_cost, tip_percent, tax_percent);

    return 0;
}

