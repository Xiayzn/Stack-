#include "Stack.h"
#include<stdio.h>

void TestStackInit()
{
	Stack s;
	StackInit(&s);
	//StackInit(NULL);

}

void TestStackPush()
{
	Stack s;
	StackInit(&s);
	StackPush(&s, 1);
	StackPush(&s, 2);
	StackPush(&s, 3);
	StackPush(&s, 4);
	StackPush(&s, 5);
	StackPush(&s, 6);
	StackPush(&s, 7);
	StackPush(&s, 8);
	StackPush(&s, 9);
	StackPush(&s, 0);
	PrintStack(&s);

	StackPush(&s, 1);
	PrintStack(&s);

}

void TestStackPop()
{
	Stack s;
	StackInit(&s);
	StackPop(&s);

	StackPush(&s, 1);
	StackPush(&s, 2);
	StackPush(&s, 3);
	StackPush(&s, 4);
	StackPush(&s, 5);
	StackPush(&s, 6);
	StackPush(&s, 7);
	StackPush(&s, 8);
	StackPush(&s, 9);
	StackPush(&s, 0);
	PrintStack(&s);

	StackPop(&s);
	PrintStack(&s);
}

void TestPrintStack()
{
	Stack s;
	StackInit(&s);
	StackPush(&s, 1);
	PrintStack(&s);
}

void TestStackTop()
{
	Stack s;
	StackInit(&s);
	//printf("%d\n",StackTop(&s));

	StackPush(&s, 1);
	StackPush(&s, 2);
	StackPush(&s, 3);
	StackPush(&s, 4);
	printf("%d\n", StackTop(&s));
	printf("%d\n", StackTop(&s));
}

void TestStackSize()
{
	Stack s;
	StackInit(&s);
	printf("%d\n", StackSize(&s));

	StackPush(&s, 1);
	StackPush(&s, 2);
	StackPush(&s, 3);
	StackPush(&s, 4);
	printf("%d\n", StackSize(&s));

}

void TestMatchBrackets()
{
	Stack s;
	const char * str1 = "abc([])c{}}";
	const char * str2 = "abc([])c{}{";
	const char * str3 = "abc([])c(]}";
	const char * str4 = "abc([])c{}";
	StackInit(&s);

	//printf("%d\n", MatchBrackets(&s, str4));

	//printf("%d\n",MatchBrackets(&s, str1));
	//printf("%d\n", MatchBrackets(&s, str2));
	printf("%d\n", MatchBrackets(&s, str3));
}

void TestRPN()
{
	Stack s;
	const char* str = "12 3 4 + * 6 - 8 2 / +";
	StackInit(&s);

	printf("%d\n", RPN(&s, str));

}

void TestFindSpace()
{
	char* str = "abc ab";
	printf("%d\n", FindSpace(&str[0]));
}
int main()
{
	//TestStackInit();
	//TestStackPush();
	//TestStackPop();
	//TestPrintStack();
	//TestStackTop();
	//TestStackSize();
	//TestMatchBrackets();
	//TestFindSpace();
	TestRPN();
	return 0;
}
