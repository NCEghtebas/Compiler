/*
 * Premilinary Calculator
 * 1-1-15
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define OPS 4

int opernum = 0;

char operators[OPS]={'*','/','+','-'};
char op = '0';
int oper[2] = {0, 0};
int hasoperand[2]= {0, 0};

//idetermines if an input harater an operator or not
int isOperator(char c){
	for(int i=0; i<OPS; i++){
		if(c == operators[i]){
			return 1;
		}
	}
	return 0;
}

//turns string of charaters into an int
void digitize(char input){
	int temp = input - '0';
	// printf("temp %d\n", temp);
	oper[opernum] = oper[opernum]*10 + temp;
	hasoperand[opernum] = 1;
	printf("oper[opernum] %d\n", oper[opernum]);
}

//calculates operation between oper[0] and oper[1]
int calculate(){
	int result;
	switch (op){
	case '+':
		result= oper[0] + oper[1];
		break;
	case '-':
		result= oper[0] - oper[1];
		break;
	case '/':	
		result= oper[0] / oper[1];
		break;
	case '*':
		result= oper[0] * oper[1];
		break;
	default:
		printf("Invalid operation: %c\n", op);
	}
	return result;
}

void resetnum(){
	hasoperand[0] = 0;
	hasoperand[1] = 0;
	opernum = 0;
	oper[0] = 0;
	oper[1] = 0;
	op= '0';
	puts("Reset");
}

void scanner(char* input, int len){
	for(int i=0; i<len; i++){
		if(isOperator(input[i])==1){
			printf("encountered operator %c\n", input[i]);
			if(op == '0'){
				op = input[i];
			}else if( (hasoperand[0] == 1) && (hasoperand[1] == 1)){
				oper[0] = calculate();
				oper[1] = 0;
				op = input[i];
				printf("calculated result (1) %d\n", oper[0]);
			}else{
				puts("input error");
				resetnum();		
			}
			opernum= 1;
		}else if(isdigit(input[i]) != 0){
			printf("input digit %c\n", input[i]);
			digitize(input[i]);

		}else if ((hasoperand[0] == 1) && (hasoperand[1] == 1) && (op != '0')){
			oper[0] = calculate();
			oper[1] = 0;
			printf("calculated result (2) %d\n", oper[0]);
		}else if(input[i] == '\n'){
			resetnum();
			puts("User input complete");
		}else{						
			printf("not valid input %c\n", input[i]);
		}
	}	
	printf("oper1 and oper 2: %d, %d\n", oper[0], oper[1]);
	resetnum();
}

int main(){
	char * userin = (char *) malloc(80);
	size_t mylen;
	for(;;)
	{	
		printf(": ");
		userin= fgetln(stdin, &mylen);
		// printf("length of input %d\n", (int) mylen);
		printf("user input: %s\n",userin);		
		scanner(userin, (int) mylen);
	}
	return 1;
}
