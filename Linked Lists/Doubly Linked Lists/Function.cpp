#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
struct Node
{
	int data;
	struct Node *next;
	struct Node *prev;
};

void push(struct Node** head_ref, int new_data)
{
	
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	
	new_node->data = new_data;
	
	new_node->next = (*head_ref);
	new_node->prev = NULL;
	
	if((*head_ref) != NULL )
		(*head_ref)->prev = new_node;
	
	(*head_ref) = new_node;
}

void insertAfter(struct Node* prev_node, int new_data) 
{ 
 
    if (prev_node == NULL) { 
        printf("the given previous node cannot be NULL"); 
        return; 
    } 
  
 
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node)); 
  
 
    new_node->data = new_data; 
  

    new_node->next = prev_node->next; 
  

    prev_node->next = new_node; 
  
 
    new_node->prev = prev_node; 
  
  
    if (new_node->next != NULL) 
        new_node->next->prev = new_node; 
}

void append(struct Node** head_ref, int new_data) 
{ 
    
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node)); 
  
    struct Node* last = *head_ref;  
    
    new_node->data = new_data; 
  
 
    new_node->next = NULL; 
  

    if (*head_ref == NULL) { 
        new_node->prev = NULL; 
        *head_ref = new_node; 
        return; 
    } 
  
 
    while (last->next != NULL) 
        last = last->next; 
  
    last->next = new_node; 
  

    new_node->prev = last; 
  
    return; 
} 

void insertBefore(struct Node** head_ref, struct Node* next_node, int new_data)  
{  
    
    if (next_node == NULL) {  
        printf("the given next node cannot be NULL");  
        return;  
    }  
  
    
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));  
  
    
    new_node->data = new_data;  
  
    
    new_node->prev = next_node->prev;  
  
    
    next_node->prev = new_node;  
  
    
    new_node->next = next_node;  
  
   
    if (new_node->prev != NULL)  
        new_node->prev->next = new_node;  
    else
        (*head_ref) = new_node; 
}

void printList(Node* node)  
{  
    Node* last;  
    cout<<"\nTraversal in forward direction \n";  
    while (node != NULL)  
    {  
        cout<<" "<<node->data<<" ";  
        last = node;  
        node = node->next;  
    }  
  
    cout<<"\nTraversal in reverse direction \n";  
    while (last != NULL)  
    {  
        cout<<" "<<last->data<<" ";  
        last = last->prev;  
    }  
}

void reverse(Node **head_ref)  
{  
    Node *temp = NULL;  
    Node *current = *head_ref;  
      

    while (current != NULL)  
    {  
        temp = current->prev;  
        current->prev = current->next;  
        current->next = temp;              
        current = current->prev;  
    }  
      

    if(temp != NULL )  
        *head_ref = temp->prev;  
}  

void swap(int *A, int *B)  
{  
    int temp = *A;  
    *A = *B;  
    *B = temp;  
}  

Node *split(Node *head)  
{  
    Node *fast = head,*slow = head;  
    while (fast->next && fast->next->next)  
    {  
        fast = fast->next->next;  
        slow = slow->next;  
    }  
    Node *temp = slow->next;  
    slow->next = NULL;  
    return temp;  
}    
  

Node *merge(Node *first, Node *second)  
{  
    
    if (!first)  
        return second;  
  
    
    if (!second)  
        return first;  
  
    
    if (first->data < second->data)  
    {  
        first->next = merge(first->next,second);  
        first->next->prev = first;  
        first->prev = NULL;  
        return first;  
    }  
    else
    {  
        second->next = merge(first,second->next);  
        second->next->prev = second;  
        second->prev = NULL;  
        return second;  
    }  
}  
  
 
Node *mergeSort(Node *head)  
{  
    if (!head || !head->next)  
        return head;  
    Node *second = split(head);  
  
    
    head = mergeSort(head);  
    second = mergeSort(second);  
  
    
    return merge(head,second);  
}  

//added swap node functionality by changing pointers instead of data

void swapNodes(Node **head_ref, int x, int y)  
{  
 
if (x == y) return;  
  
  
Node *prevX = NULL, *currX = *head_ref;  
while (currX && currX->data != x)  
{  
    prevX = currX;  
    currX = currX->next;  
}  
  
  
Node *prevY = NULL, *currY = *head_ref;  
while (currY && currY->data != y)  
{  
    prevY = currY;  
    currY = currY->next;  
}  
  
  
if (currX == NULL || currY == NULL)  
    return;  
  
 
if (prevX != NULL)  
    prevX->next = currY;  
else  
    *head_ref = currY;  
  
  
if (prevY != NULL)  
    prevY->next = currX;  
else 
    *head_ref = currX;  
  

Node *temp = currY->next;  
currY->next = currX->next;  
currX->next = temp;  
}


//added main function to check the swap functionality of the pointer nodes
int main()  
{  
    Node *start = NULL;  
  
    push(&start, 7);  
    push(&start, 6);  
    push(&start, 5);  
    push(&start, 4);  
    push(&start, 3);  
    push(&start, 2);  
    push(&start, 1);  
  
    cout << "Linked list before calling swapNodes() ";  
    printList(start);  
  
    swapNodes(&start, 4, 3);  
  
    cout << "\nLinked list after calling swapNodes() ";  
    printList(start);  
  
    return 0;  
}  