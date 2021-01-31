#include "Birthday.h"

using namespace std;

Birthday::Birthday(int a, int b, int c) {
    day = a;
    month = b;    
    year = c;
}

void Birthday::print() {
    cout << day << "/" << month << "/" << year << endl;
}
