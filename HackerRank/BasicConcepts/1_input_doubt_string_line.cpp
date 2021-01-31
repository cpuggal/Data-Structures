// https://www.hackerrank.com/challenges/30-data-types/problem
//

#include <iostream>
#include <iomanip>
#include <limits>

using namespace std;

int main() {
    int i = 4;
    double d = 4.0;
    string s = "HackerRank ";

    int j;
    double d1;
    string str;
    cin >> j >> d1;
    getline(cin, str);

    while (str.length()==0 ) 
        getline(cin, str);
    
    cout << (i+j) << endl;
    cout << fixed << setprecision(1) ;
    cout << (d+d1) << endl;
    cout << s << str << endl;

    // Declare second integer, double, and String variables.
    
    // Read and save an integer, double, and String to your variables.
    // Note: If you have trouble reading the entire string, please go back and review the Tutorial closely.
    
    // Print the sum of both integer variables on a new line.
    
    // Print the sum of the double variables on a new line.
    
    // Concatenate and print the String variables on a new line
    // The 's' variable above should be printed first.

    return 0;
}
