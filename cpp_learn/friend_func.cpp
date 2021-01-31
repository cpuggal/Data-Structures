#include<iostream>

using namespace std;

class StankFirst{
    public:
        StankFirst(){
            cout << "Constructor called" << endl;
            stinkyVar = 0;
        }
        ~StankFirst(){
            cout << "Destructor called" << endl;
        }
        void printInfo() {
            cout << stinkyVar << endl;
         }
    private:
        int stinkyVar;

    friend void StankyFriend(StankFirst &sfo, int var);
};

void StankyFriend(StankFirst &sfo, int var) {
    sfo.stinkyVar = var;
    cout << "Friend func update odj private variable to : " << sfo.stinkyVar << endl;
}

int main() {
    StankFirst sfo;
    sfo.printInfo();
    StankyFriend(sfo, 100);
    sfo.printInfo();
    return 0;
}
