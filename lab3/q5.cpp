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
    void insert_at_head(string val)
    {
        node* temp=new node(val);
        temp->next=head;
        head=temp;
        cout<<"Inserted!"<<endl;
    }
    void delete_at_head()
    {
        if(!head)
        {
            cout<<"List is already empty!"<<endl;
            return;
        }
        node* todel=head;
        head=head->next;
        delete todel;
        todel=nullptr;
        cout<<"Ticket Sold!"<<endl;
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
            cout<<"Person "<<count++<<": "<<temp->val<<endl;
            temp=temp->next;
        }
    }
};
int main()
{
    linkedList l;
    int choice;
    string name;

    cout<<"Ticket Counter System"<<endl;
    while(true)
    {
        cout<<"\n1. Add Person\n";
        cout<<"2. Sell Ticket (remove person at head)\n";
        cout<<"3. Display Queue\n";
        cout<<"4. Exit\n";
        cout<<"Enter your choice: ";
        cin>>choice;
        cin.ignore();

        switch(choice)
        {
            case 1:
                cout<<"Enter person's name: ";
                getline(cin, name);
                l.insert_at_head(name);
                cout<<"Person added to the list!"<<endl;
                break;

            case 2:
                l.delete_at_head();
                break;

            case 3:
                l.printlist();
                break;

            case 4:
                cout<<"Exiting... Goodbye!"<<endl;
                return 0;

            default:
                cout<<"Invalid choice! Try again."<<endl;
        }
    }
}