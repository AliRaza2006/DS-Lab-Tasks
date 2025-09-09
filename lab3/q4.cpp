#include<iostream>
using namespace std;
class node
{
    public:
    node* next;
    node* prev;
    int val;
    node():val(0),next(nullptr),prev(nullptr){}
    node(int dat):val(dat),next(nullptr),prev(nullptr){}
};
class linkedList
{
    public:
    node* head;
    node* curr;
    int index;
    int sizeOfList;
    linkedList():head(nullptr),curr(nullptr),index(0),sizeOfList(0){}
    void insertAtEnd(int val)
    {
        if(!head)
        {
            head=new node(val);
            curr=head;
            index=1;
            sizeOfList=1;
            return;
        }
        node* temp=head;
        while(temp->next!=nullptr)
        {
            temp=temp->next;
        }
        temp->next=new node(val);
        temp->next->prev=temp;
        sizeOfList++;
    }
    void printList()
    {
        if(!head)
        {
            cout<<"List is empty!"<<endl;
            return;
        }
        node* temp=head;
        int i=1;
        while(temp)
        {
            cout<<i++<<". "<<temp->val<<endl;
            temp=temp->next;
        }
    }
    void forward(int step)
    {
        int c=0;
        if(index+step>sizeOfList)
        {
            cout<<"Cannot move "<<step<<" steps forward!"<<endl;
            return;
        }
        else
        {
            while(c!=step && curr)
            {
                curr=curr->next;
                c++;
            }
            if(curr)
            {
                cout<<curr->val<<endl;
                index+=step;
            }
            else
            {
                cout<<"Cannot move "<<step<<" steps forward!"<<endl;
            }
        }
    }
    void backward(int step)
    {
        int c=0;
        if(step>=index)
        {
            cout<<"Cannot move "<<step<<" steps backward!"<<endl;
            return;
        }
        else
        {
            while(c!=step && curr)
            {
                curr=curr->prev;
                c++;
            }
            if(curr)
            {
                cout<<curr->val<<endl;
                index-=step;
            }
            else
            {
                cout<<"Cannot move "<<step<<" steps backward!"<<endl;
            }
        }
    }
};
int main() {
    linkedList list;
    int choice,step;
    int val;

    while (1) {
        cout << "\nBanking Application\n";
        cout << "1. Make a new transaction\n";
        cout << "2. Move Forward\n";
        cout << "3. Move Backward\n";
        cout << "4. Print History\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter Amount: ";
                cin >> val;
                list.insertAtEnd(val);
                break;

            case 2:
                cout << "Enter steps forward: ";
                cin >> step;
                list.forward(step);
                break;

            case 3:
                cout << "Enter steps backward: ";
                cin >> step;
                list.backward(step);
                break;

            case 4:
                list.printList();
                break;

            case 5:
                cout << "Exiting..." << endl;
                return 0;

            default:
                cout << "Invalid choice! Try again." << endl;
        }
    }
}