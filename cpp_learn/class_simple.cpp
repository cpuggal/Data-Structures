#include<iostream>

using namespace std;

class Book{
    public:
        int pages;
        string title;
        string author;
        
        Book(int Pages, string Title, string Author) {
            this->pages = Pages;
            this->title = Title;
            this->author = Author;
        }

        void print_details() {
            cout << "Book title: " << this->title << " is authored by : " << this->author << " having pages : " << this->pages << endl;
        }
};

int main()
{
    Book b1(100, "Learn C++", "Narsima");
    Book b2(200, "Peeling Design Patterns", "Narsima Karumachi");
    b1.print_details();
    b2.print_details();
    return 0;
}



