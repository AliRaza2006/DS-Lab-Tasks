#include<iostream>
using namespace std;
class node
{
    public:
    node* next;
    string val;
    node():val(""),next(nullptr){}
    node(string dat):val(dat),next(nullptr){}
};
class linkedList
{
    public:
    node* head;
    linkedList():head(nullptr){}
    void insertAtEnd(string val)
    {
        if(!head)
        {
            head=new node(val);
            return;
        }
        node* temp=head;
        while(temp->next!=nullptr)
        {
            temp=temp->next;
        }
        temp->next=new node(val);
    }
    void insertAthead(string val)
    {
        node* newnode=new node(val);
        newnode->next=head;
        head=newnode;
    }
    void deleteTask(int num)
    {
        if(!head)
        {
            cout<<"List is empty!"<<endl;
            return;
        }
        int c=1;
        node* temp=head;
        node* prev=head;
        while(c!=num && temp!=nullptr)
        {
            prev=temp;
            temp=temp->next;
            c++;
        }
        if(temp)
        {
            if(temp==head)
            {
                node* todel=head;
                head=head->next;
                delete todel;
                todel=nullptr;
                cout<<"Task deleted! "<<endl;
                return;
            } 
            node* todel=temp;
            prev->next=temp->next;
            delete todel;
            todel=nullptr;
            cout<<"Task deleted! "<<endl;
        }
        else
        {
            cout<<"Task not found!"<<endl;
        }
    }
    void printlist()
    {
        node* temp=head;
        if(!head)
        {
            cout<<"Empty list!"<<endl;
            return;
        }
        int count=1;
        while(temp)
        {
            cout<<"Task "<<count++<<": "<<temp->val<<endl;
            temp=temp->next;
        }
    }
};
int main()
{
    linkedList l;
    cout <<"Task Manager\n";
    while(1)
    {
        int choice;
        cout << "\n1. Add New Task (at end)\n";
        cout << "2. Add Urgent Task (at beginning)\n";
        cout << "3. Delete Completed Task\n";
        cout << "4. Display All Tasks\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cout<<endl;
        cin.ignore();
        switch(choice)
        {
            case 1:
            {
                string task;
                cout<<"Task to add: ";
                getline(cin,task);
                l.insertAtEnd(task);
                cout<<"Task added!\n";
                break;
            }
            case 2:
            {
                string task;
                cout<<"Task to add: ";
                getline(cin,task);
                l.insertAthead(task);
                cout<<"Task added!\n";
                break;
            }
            case 3:
            {
                cout<<"Enter the serial number of task to delete: ";
                int num;
                cin>>num;
                cin.ignore();
                l.deleteTask(num);
                break;                
            }
            case 4:
            {
                l.printlist();
                break;
            }
            case 5:
            {
                cout<<"Thank for using our program"<<endl;
                return 0;
            }
            default:
            {
                cout<<"Wrong choice!";
            }
        }
    }
}