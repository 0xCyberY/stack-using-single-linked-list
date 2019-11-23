//stacks_link.c
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct node
{
   int data;
   struct node *link;
};
   typedef struct node *NODE;
   NODE push(int element, NODE first)
   {
	NODE temp = NULL, current = NULL;
	if((temp = (NODE*)malloc(sizeof(NODE))) != NULL)
	{
	   temp->data = element;
	   temp->link = NULL;
	if(first == NULL)
	   return temp;
	   current = first;
		while(current->link != NULL)
	   	current = current->link;
	   	current->link = temp;
	   	return first;
	}
	else
	{
	   printf("\n Insufficient Memory ");
	   exit(0);
	}
   }
NODE pop(NODE first)
{
	if(first == NULL)
	{
	   printf("\n Stack is empty, Nothing to pop");
	   return first;
	}
	else if(first->link == NULL)
	{
	   printf("\n Element deleted is %d ",first->data);
	   free(first);
	   return NULL;
	}
	else
	{
	   NODE current = first, previous = NULL;
		while(current->link != NULL)
	        {
			previous = current;
			current = current->link;
	   	}
	   previous->link = NULL;
	   printf("\n Element deleted is %d ",current->data);
	   free(current);
	   return first;
	}
}
void display(NODE first)
{
NODE current = NULL;
   if(first == NULL)
   {
	printf("\n Nothing to display, Stack is empty !! \n");
   }
   else
   {
	current = first;
	while(current != NULL)
	{
		printf("%d->",current->data);
		current = current->link;
	}
   }
}
void main()
{
NODE first = NULL;
int choice,element;
   while(1)
   {
	printf("\n --STACK IMPLEMENTATION USING LINKED LIST-- \n");
	printf("\n 1) Push \n 2) Pop \n 3) Display \n 4) Exit \nPlease Enter your choice : \n");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			printf("\n Enter the element to be pushed intothe stack : \n");
			scanf("%d",&element);
			first = push(element,first);
			break;
		case 2:
			first = pop(first);
			break;
		case 3:
			display(first);
			break;
		case 4:
			exit(0);
			break;
		default : printf("\n Please enter the correct choice\n");
			break;
	}
   }
}
