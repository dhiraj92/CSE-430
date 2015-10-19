#include"q.h"

int main()
{
	puts("hi");
	int i = 1;
	puts("hi");
	
	int x = 5;
	
	puts("hi");
	p();
	InitQueue(&head);
	struct Queue *ptr= NewItem(x);
	struct Queue *del;
	if(head == NULL || ptr->next == NULL)
	{
		printf("head not intialized \n");
	}
	AddQueue(&head,ptr);
	printf("%d\n",x);
	if(head == NULL || ptr->next == NULL)
	{
		printf("head not intialized");
	}
	//head=ptr;
	x=x+1;
	printf("ptr %d",head->payload);
	ptr= NewItem(x);
	AddQueue(&head,ptr);
	printf("%d",head->next->payload);
	x=x+1;
	printf("ptr %d",head->payload);
	ptr= NewItem(x);
	AddQueue(&head,ptr);
	printf("%d",head->next->next->next->payload);
	RotateQ(&head);
	printf("%d",head->payload);
	del=DelQueue(&head);
	DelQueue(&head);
	DelQueue(&head);
	DelQueue(&head);
	DelQueue(&head);
	printf("%d \n",del->payload);
	RotateQ(&head);
	return 0;

}