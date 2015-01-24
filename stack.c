#include <stdio.h>

int oper[128];
int stackindex = 0;

void push(int item){
	if(stackindex>=128){
		puts("Stack is full");
	}else{
		oper[stackindex] = item;
		stackindex ++;
	}
	println("pushed %d onto stack at %d", item, stackindex);
}

void pop(int* item){
	if(stackindex <=0 ){
		puts("Stack index is empty");
		item = NULL;
	}else{
		stackindex --; 
		item = &oper[stackindex];
	}
}