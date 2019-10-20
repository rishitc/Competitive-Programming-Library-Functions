// C program to implement Stack using array //
// Written by: @ExpressHermes

#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

int stack[SIZE];
int top = -1;

void push(int value) {
    if(top == SIZE -1) 
        printf("\nOverflow. Stack is full\n");
    else {
        top++;
        stack[top] = value;
        printf("\nInsertion was successful\n");
    }
}

void pop() {
    if(top == -1)
        printf("\nUnderflow. Stack is empty\n");
    else {
        printf("\nPopped Value: %d\n", stack[top]);
        top--;
    }
}

void display() {
    if(top == -1)
        printf("\nStack is empty \n");
    else {
        printf("Stack elements are: ");
        for(int i = top; i >= 0; i--)
            printf("%d\t", stack[i]);
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


