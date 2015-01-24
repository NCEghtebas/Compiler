SRCS = stack.c calculator.c
OBJS = stack.o calculator.o

calculator : $(OBJS)
	gcc -o calculator $(OBJS)

stack.o : stack.c

calculator.o : calculator.c

clean :
	rm $OBJS

