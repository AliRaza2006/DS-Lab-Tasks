#include<iostream>
using namespace std;
class Person{
	public:
	int age;
	string name;
    Person(){
    	age=19;
    	name="DS Lab Student";
	}	
	//Parameterize Constructor 
	Person(int a,string n){	
       age=a;
	   name=n;	
}
	//Copy Constructor 
	Person(const Person &other){
		this->age=other.age;
		this->name=other.name;
	}
	//Copy Assignemt Operator 
	Person& operator=(const Person &other){
		if(this!=&other){
			age=other.age;
			name=other.name;
		}
		else{
			return *this;
		}
	}
  ~Person(){
  	cout<<"String Does not need to be deallocated "<<endl;
  }	
  void display(){
  	cout<<age<<endl;
  	cout<<name<<endl;
  	
  }
};
int main(){
	Person p1(43,"Zaha Ali Khan");
	Person p2=p1; //Shallow copy 
	p1.display();
	p2.display();

p1.name="Fast NUCES karachi Campus ";
	p1.display();
	p2.display();
};
