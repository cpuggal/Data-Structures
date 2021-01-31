#include "People.h"

using namespace std;

People::People(string aName, Birthday dob) 
: name(aName), dateOfBirth(dob)
{

}

void People::printInfo() {
    cout << "User Name : " << name << " was born on ";
    dateOfBirth.print();
}
