/*============================================================================

Title:   Reversing string using Stack

============================================================================*/

#include<iostream>
#include<string.h>
using namespace std;


class Revstr{
	int top;
	char st[20];

	public:
	void accept(char d);
	void display();

	Revstr()
	{
		top=-1;
	}
};
	void Revstr::accept(char data)
	{
			 top++;
			 st[top]=data;
	}
	void Revstr::display()
	{
		cout<<"Reverse of the string is: \n"<<endl;
		while(top>=0)
		{
			cout<<st[top];
			top--;
		}
	}


int main() {
	Revstr s1;
	char data[20];
    int i;

	cout<<"Enter the string : "<<endl;
	cin>>data;
	for(i=0;i<strlen(data);i++)
    {
        s1.accept(data[i]);
    }
	s1.display();
    return 0;
}

//OUTPUT:
//
//Enter the string :
//myString
//Reverse of the string is:
//
//gnirtSym
