#define THREADS_H
#include "q.h"

struct TCB_t *runQ;
void startThread(void (*function)(void));
void run();
void yield();
void startThread(void (*function)(void)) {
	//printf("Inside StartThread");
	TCB_t *temp = NewItem();
	void *stack = (void *) malloc(8192);
	init_TCB(temp, function, stack, 8192);
	addQueue(&runQ, temp);
	//printf("Thread added");
	return;
}

void run() {
	//printf("Inside Run");
	ucontext_t parent;	
	getcontext(&parent);	
	swapcontext(&parent, &(runQ->context));
	return;
}

void yield() {
	//printf("Inside Yield");
	ucontext_t curr, next;	
	getcontext(&curr);
	runQ->context = curr;
	RotateQ(&runQ);
	next = runQ->context;
	swapcontext(&curr, &next);
	//printf("Yield done");

	return;
}


