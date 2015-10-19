
#include <stdio.h>
#include <stdlib.h>
#include "tcb.h"


/*  struct TCB_t
{
	struct TCB_t *next;
	struct TCB_t *prev;
	int payload;
}; */

struct TCB_t *head ;

//typedef struct TCB_t *node; 
//struct TCB_t *head;

void initQueue(struct TCB_t **head);
struct TCB_t* NewItem();
void addQueue(struct TCB_t **head, struct TCB_t *ptr);
struct TCB_t* delQueue(struct TCB_t **head);
void RotateQ(struct TCB_t **head);

void initQueue(struct TCB_t **head)
{
	//printf("Head intializlizing\n");
	(*head) = NULL;
	//printf("Head intialized\n");
}

struct TCB_t* NewItem()
{
	//printf("indie new\n");
	struct TCB_t *N = (struct TCB_t*)malloc(sizeof(struct TCB_t));
	N->prev = NULL;
	N->next = NULL;
	//N->payload = x;
	//printf("new item created \n");
	return N;
}


void addQueue(struct TCB_t **head, struct TCB_t *ptr)
{
	
	if(ptr == NULL)
	{
		//printf("ptr null");
	}
	
	if (*head == NULL)
	{
		//printf("first item added %d\n",ptr->payload);
		
		ptr->next = ptr;
		ptr->prev = ptr;
		*head = ptr;
		
	}
	
	else
	{
		//printf("new item added %d\n",ptr->payload);
		
		(*head)->prev->next=ptr;
		ptr->prev=(*head)->prev->next;
		(*head)->prev=ptr;
		ptr->next=(*head);
		
		
	}
}

struct TCB_t* delQueue(struct TCB_t **head)
{
	struct TCB_t *temp=(struct TCB_t*)malloc(sizeof(struct TCB_t));;
	if (*head == NULL)
	{
		//printf("List empty");
		return NULL;
	}

	else if ((*head)->next == (*head))
	{
		//printf("last element deleted");
		
		temp = *head;
		//printf("%d \n",temp->payload);
		*head = NULL;
		return NULL;
	}

	else
	{
		//printf("element deleted \n");
		temp = *head;
		(*head)->next->prev = (*head)->prev;
		(*head)->prev->next = (*head)->next;
		(*head) = (*head)->next;
		//printf("%d \n",(*head)->payload);
		//printf("%d \n",temp->payload);
	}
	
	return temp;
}


void RotateQ(struct TCB_t **head)

{
	if(*head == NULL)
	{
		//printf("List empty");
	}
	else
	{
		//printf("Rotated\n");
		(*head) = (*head)->next;
	}
}
