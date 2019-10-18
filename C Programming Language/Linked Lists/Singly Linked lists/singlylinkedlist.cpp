//Program for singly linked list

#include <iostream>
using namespace std;
#include <string.h>

class node
{
friend class list;
int rollno;
char name[10];
int year;
node *next;

public:
node(int d,int r,char s[10])
{
	rollno=d;
	year=r;
	strcpy(name,s);
	next=NULL;
}

};

class list
{
	node *head;

    public:
	list()
	{
		head=NULL;
	}
	void createmember()
	{
		int r,y;
		char a;
		char nm[10];
		node *temp,*ptr;

        do
        {

            cout<<"Enter roll no, year and name: "<<endl;
            cin>>r>>y>>nm;

            temp= new node(r,y,nm);

			if(head==NULL)
			{
				head=temp;
				cout<<"Node is inserted"<<endl;
			}
			else
			{
				ptr=head;
				while(ptr->next!=NULL)
				{
					ptr=ptr->next;
				}
				ptr->next=temp;
				cout<<"Node is inserted"<<endl;
			}
            cout<<"\nDo you want to continue the process, if yes say 'y'";
            cin>>a;
        }while(a=='y'||a=='Y');

	}

	void display()
	{
		node *ptr;

		if(head==NULL)
		{
			cout<<"List is empty"<<endl;
		}
		else
		{
			ptr=head;
			while(ptr!=NULL)
			{
				cout<<"Rollno: "<<ptr->rollno<<endl;
				cout<<"Year: "<<ptr->year<<endl;
				cout<<"Name: "<<ptr->name<<endl;
				cout<<endl;
				ptr=ptr->next;
			}
		}
	}
	int count()
	{
		node *ptr;
		int count=0;

		if(head==NULL)
		{
			return 0;
		}
		else
		{
			ptr=head;
			while(ptr!=NULL)
			{
				count++;
				ptr=ptr->next;
			}
			return count;
		}
	}
	void insert()
	{
			int r,y,i,pos;
			char nm[10];
			node *temp,*ptr;

			cout<<"Enter roll no, year and name: "<<endl;
			cin>>r>>y>>nm;
			temp= new node(r,y,nm);

			cout<<"Enter the position you want to insert: "<<endl;
			cin>>pos;

			if(pos==1)
			{
				temp->next=head;
				head=temp;
				cout<<"Node is inserted"<<endl;
			}
			else if(pos<=count()+1)
			{
				ptr=head;
				for(i=2;i<=pos-1;i++)
				{
					ptr=ptr->next;
				}
				temp->next=ptr->next;
				ptr->next=temp;
                cout<<"Node is inserted"<<endl;
			}
            else
                cout<<"Position not found!"<<endl;

//			LAST NODE
//          {
//				ptr=head;
//				while(ptr->next!=NULL)
//					ptr=ptr->next;
//				ptr->next=temp;
//			}

	}
	void deletemember()
	{
		int data;
		node *ptr,*prev;
		int flag=0;
        ptr=head;

		if(head==NULL)
        {
            cout<<"List is empty!"<<endl;
            return;
        }

		cout<<"Enter the rollno to be deleted"<<endl;
		cin>>data;
		if(ptr->rollno==data)
        {
            head=head->next;
            delete ptr;
            flag=1;
        }
        else
        {
            while((ptr!=NULL)&&(ptr->rollno!=data))
            {
                prev=ptr;
                ptr=ptr->next;
            }
            if(ptr==NULL)
                flag=0;
            else
            {
                prev->next=ptr->next;
                ptr->next=NULL;
                delete ptr;
                flag=1;
            }
        }
        if(flag==0)
            cout<<"Roll no. not present!"<<endl;
        else
            cout<<"Node successfully deleted!"<<endl;

        display();

	}

};

int main() {

	list l1;
	int ch;
	int count=0;

	l1.createmember();
	cout<<"1.Display"<<endl;
	cout<<"2.Count"<<endl;
	cout<<"3.Insert"<<endl;
	cout<<"4.Delete"<<endl;
	cout<<"5.Exit"<<endl;

	while(1)
	{
		cout<<"Enter your choice: "<<endl;
		cin>>ch;
		switch(ch)
		{
			case 1:
					l1.display();
					break;

			case 2:
                    cout<<"Total number of nodes: "<<l1.count()<<endl;
					break;

			case 3:
					l1.insert();
					break;

			case 4:
					l1.deletemember();
					break;

            case 5:
                    cout<<"Program closed!"<<endl;
                    //exit(1);
                    break;

			default:
					cout<<"Invalid choice"<<endl;
					break;

		}
	}
	return 0;
}

/*
OUTPUT:

Enter roll no, year and name:
1
2000
abc
Node is inserted

Do you want to continue the process, if yes say 'y' or say 'n' y
Enter roll no, year and name:
2
2000
abc
Node is inserted

Do you want to continue the process, if yes say 'y' or say 'n' n
1.Display
2.Count
3.Insert
4.Delete
5.Exit
Enter your choice:
1
Rollno: 1
Year: 2000
Name: abc

Rollno: 2
Year: 2000
Name: abc

Enter your choice:
3
Enter roll no, year and name:
3
2000
abc
Enter the position you want to insert:
4
Position not found!
Enter your choice:
4
Enter the rollno to be deleted
3
Roll no. not present!
Enter your choice:
4
Enter the rollno to be deleted
1
Node successfully deleted
Enter your choice:
1
Rollno: 2
Year: 2000
Name: abc

Enter your choice:
2
Total number of nodes: 1
Enter your choice:
3
Enter roll no, year and name:
1
2000
abc
Enter the position you want to insert:
1
Node is inserted
Enter your choice:
1
Rollno: 1
Year: 2000
Name: abc

Rollno: 2
Year: 2000
Name: abc

Enter your choice:
5
Program closed!

*/
