#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struck Node *next;
	struck Node *prev;
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

