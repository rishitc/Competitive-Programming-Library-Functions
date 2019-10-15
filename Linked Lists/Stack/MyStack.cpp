/*============================================================================

Title:   Implementation of Stack using Array

============================================================================*/

#include<iostream>
using namespace std;


class stack{
	int top;
	int st[20];
	int MAXSIZE=3;
	public:
	void push(int d);
	int pop();
	void display_top();
	int isempty();
	int isfull();
	void display();

	stack()
	{
		top=-1;
	}
};

	int stack::isempty()
	{
		if(top==-1)
			return 1;
		return 0;
	}
	int stack::isfull()
	{
		if(top==MAXSIZE-1)
			return 1;
		return 0;
	}
	void stack::push(int data)
	{
		 if(isfull()==0)
		 {
			 top++;
			 st[top]=data;
		 }
		 else
			 cout<<"Stack is full"<<endl;
	}
	int stack::pop()
	{
		int data;
		if(isempty()==0)
		{
			data=st[top];
			top--;
			return data;
		}
		else
        {
            cout<<"Stack is empty"<<endl;
            return 0;
        }

	}
	void stack::display()
	{
		int temp=top;
		cout<<"Your stack is: "<<endl;
		while(top>=0)
		{
			cout<<st[top]<<endl;
			top--;
		}
		top=temp;
	}
	void stack::display_top()
	{
		cout<<"Element "<<st[top]<<" is at position "<<top<<endl;
	}

int main() {
	stack s1;
	int ch,data;
	cout<<"1.Push"<<endl;
	cout<<"2.Pop"<<endl;
	cout<<"3.Display"<<endl;
	cout<<"4.Display top element"<<endl;
	cout<<"5.Exit"<<endl;

	while(1)
	{
		cout<<"Enter your choice: "<<endl;
		cin>>ch;
		switch(ch)
		{
		case 1:
			cout<<"Enter the data to be inserted: "<<endl;
			cin>>data;
			s1.push(data);
			break;

		case 2:
			data=s1.pop();
			cout<<data<<" is deleted from the stack"<<endl;
			break;

		case 3:
			s1.display();
			break;

		case 4:
			s1.display_top();
			break;

		case 5:
			cout<<"Program closed!"<<endl;
			exit(1);

		default:
			cout<<"Invalid choice!";
			break;

		}
	}

}

//OUTPUT:
//
//1.Push
//2.Pop
//3.Display
//4.Display top element
//5.Exit
//Enter your choice:
//1
//Enter the data to be inserted:
//1
//Enter your choice:
//1
//Enter the data to be inserted:
//2
//Enter your choice:
//1
//Enter the data to be inserted:
//3
//Enter your choice:
//1
//Enter the data to be inserted:
//4
//Enter your choice:
//3
//Your stack is:
//4
//3
//2
//1
//Enter your choice:
//2
//4 is deleted from the stack
//Enter your choice:
//3
//Your stack is:
//3
//2
//1
//Enter your choice:
//4
//Element 3 is at position 2
//Enter your choice:
//5
//Program closed!

