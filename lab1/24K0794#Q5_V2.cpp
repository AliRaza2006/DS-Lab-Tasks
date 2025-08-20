#include<iostream>
using namespace std;
/*Create a database with Teacher class to store the teacher’s name, the subject they teach,
and their years of experience, with the name and subject stored as dynamic strings. First, write
the class without a copy constructor or assignment operator and observe what happens when
you copy one teacher object into another (shallow copy problem). Then implement the Rule of
Three to fix the issue. Display both teacher objects before and after the fix to demonstrate the
difference.*/
class Teacher
{
    private:
    string* name;
    string* subject;
    public:
    Teacher(string n,string sub){
        name=new string(n);
        subject=new string(sub);
    }
    Teacher()
    {
        name=new string("Adeel Rehman");
        subject=new string("DLD");
    }
    // Teacher(const Teacher& t)
    // {
    //     name=new string(*t.name);
    //     subject=new string(*t.subject);
    // }
    // Teacher& operator=(const Teacher& t)
    // {
    //     if(this!=&t)
    //     {
    //         delete name;
    //         delete subject;
    //         name=new string(*t.name);
    //         subject=new string(*t.subject);
    //     }
    //     return *this;
    // }
    string getName(){return *name;}
    string getSubject(){return *subject;}
    void setName(string n){*name=n;}
    void setSubject(string sub){*subject=sub;}
    void display()const
    {
        cout<<"Teacher's Name: "<<*name<<endl;
        cout<<"Subject: "<<*subject<<endl<<endl;
    }
    ~Teacher()
    {
        delete name;
        delete subject;
    }
};
void displayAll(const Teacher& t1,const Teacher& t2,const Teacher& t3)
{
    cout<<"Teacher 1: "<<endl;
    t1.display();
    cout<<"Teacher 2: "<<endl;
    t2.display();
    cout<<"Teacher 3: "<<endl;
    t3.display();
}
int main()
{
    Teacher t1("Ravia Ijaz","DS Lab");
    Teacher t2(t1);
    Teacher t3;
    t3=t1;
    cout<<"Teachers before changes: "<<endl;
    displayAll(t1,t2,t3);
    
    t2.setSubject("MVC");
    t2.setName("Alishba Tariq");

    t3.setSubject("OOP Lab");
    t3.setName("Muhammad Monis");
    /*if we don't make copy constructor or copy assignment operator then t1,t2,t3 share same memory address for name and subject and in the end all will have
    same name and subject i.e. Muhammad Monis and OOP Lab respectively.*/
    cout<<"Teachers after changes: "<<endl;
    displayAll(t1,t2,t3);
}