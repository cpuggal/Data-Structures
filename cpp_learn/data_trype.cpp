#include<iostream>
#include<cmath>

using namespace std;

int main()
{
    string name = "Chandan";
    cout << "Hey!! " << name << " " << name[0] << endl;
    name[0] = 'B';
    cout << "Hey!! " << name << " " << name[0] << endl;

    cout << name.find("dan") << endl;
    cout << name.substr(2,3) << endl;
    cout << pow(3,2) << endl;
    cout << round(4.3) << endl;
    cout << round(4.6) << endl;
    cout << ceil(4.2) << endl;
    cout << floor(4.2) << endl;
    cout << max(1,10) << endl;
    cout << min(1,10) <<endl;

    string user_name;
    cout << "Enter your name: ";
    // getline(cin, user_name);
    user_name = "Chandan Puggal";
    cout << "Hello! " << user_name << endl;
    int var = 10;
    cout << "Address of var " << &var << endl;
    int *ptr = &var;
    cout << ptr << " " << *ptr << " " << &ptr << endl;
    return 0;
}
