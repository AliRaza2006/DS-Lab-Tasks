#include<iostream>
#include<string>
using namespace std;
/*Suppose you’re making a library system. Create a Book class that stores the book’s title, author,
and price. The library system should be able to create a book with default values when details are
unknown, create a book with given details when new books are purchased, and make a copy of an
existing book record for testing purposes. In your program, create three book objects to show the
use of three different constructors:
1. Object one using the default constructor to create an object with default values.
2. Object two with given values input by the user.
3. Object three created using the copy constructor from the second book.
Display all book details to verify correct initialization and copying.*/ 
class Book
{
    private:
    string title;
    string author;
    double price;
    public:
    Book():title("Book"),author("Anonymous"),price(300){}
    Book(string t,string a,double p):title(t),author(a),price(p){}
    Book(const Book&b)
    {
        title=b.title;
        author=b.author;
        price=b.price;
    }
    void Display()
    {
        cout<<"Book title: "<<title<<endl;
        cout<<"Author: "<<author<<endl;
        cout<<"Price: "<<price<<endl;
    }
    ~Book(){}
};
int main()
{
    double price;
    string title,author;
    cout<<"Enter details for book2: "<<endl;
    cout<<"Title: ";
    getline(cin,title);
    cout<<"Author: ";
    getline(cin,author);
    cout<<"Price: ";
    cin>>price;
    cout<<endl;
    Book b1;
    Book b2(title,author,price);
    Book b3(b2);
    b1.Display();
    cout<<endl;
    b2.Display();
    cout<<endl;
    b3.Display();
    cout<<endl;
}