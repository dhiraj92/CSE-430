#include "threads.h"
int global = 0; 
void f1(void) {
	int local = 0;
	printf("THREAD 1: STARTS!!!\n");
	for (;;) {
		printf("THREAD 1:\tGLOBAL: %d\tLOCAL: %d\n", global, local);	
		global++;
		local++;
		sleep(1);
		yield();
	}

	return;
}

void f2(void) {
	int local = 0;
	printf("THREAD 2: STARTS!!!\n");
	for (;;) {
		printf("THREAD 2:\tGLOBAL: %d\tLOCAL: %d\n", global, local);	
		global++;	
		local++;
		sleep(1);
		yield();
	}
	
	return;
}

int main() {
	//printf("Inside Main");
	runQ = (struct TCB_t*) malloc(sizeof(struct TCB_t));
	initQueue(&runQ);
	startThread(f1);
	startThread(f2);	
	run();

	return 0;
}
