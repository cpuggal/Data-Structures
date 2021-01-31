#include<iostream>
#include "Birthday.h"
#include "People.h"

using namespace std;

int main() {

    Birthday dob(10,9,1987);
    People ppl("Chandan Puggal", dob);
    ppl.printInfo();

    return 0;
}

