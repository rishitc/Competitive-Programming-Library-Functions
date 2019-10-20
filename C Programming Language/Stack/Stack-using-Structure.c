// C program to implement Stack using structure //
// Written by: @ExpressHermes

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;

void push(int value) {
    
    struct Node *newNode;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode -> data = value;
    
    if(top == NULL)
        newNode -> next = NULL;
    else 
        newNode -> next = top;
    top = newNode;
    
    printf("\nInsertion was successful\n");
}

void pop() {
    if(top == NULL)
        printf("\nUnderflow. Stack is empty.\n");
    else {
        struct Node* temp = top;
        printf("Popped Value:\t%d\n", temp -> data);
        top = temp -> next;
        free(temp);
    }
}

void display() {
    if(top == NULL)
        printf("\nUnderflow. Stack is empty.\n");
    else {
        struct Node* temp = top;
        printf("Stack elements are: ");
        while(temp != NULL) {
            printf("%d\t", temp -> data);
            temp = temp -> next;
        }
        printf("\n");
    }
}

int main(void) {
	int choice, value;
	printf("\n************* STACK IMPLEMENTATION USING STRUCURES *************\n");
	
	while(1) {
    	printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
    	printf("Enter your choice: ");
    	scanf("%d",&choice);
    	
    	switch(choice) {
    	    case 1: printf("Enter value to be pushed: ");
    	            scanf("%d", &value);
    	            push(value);
    	            break;
    	    case 2: pop();
    	            break;
    	    case 3: display();
    	            break;
    	    case 4: exit(0);
    	    default: printf("\nWrong choice. Try again.\n");
    	}
	}
	return 0;
}


