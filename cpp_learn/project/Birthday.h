#ifndef BIRTHDAY_H
#define BIRTHDAY_H

#include<iostream>

using namespace std;

class Birthday{
    public:
        Birthday(int a, int b, int c);
        void print();
    private:
        int month;
        int day;
        int year;
};

#endif
