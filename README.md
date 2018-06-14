# Stack-

//Stack
#ifndef __STACK_H__
#define __STACK_H__

#pragma once

typedef int DataType;

typedef struct Stack
{
	DataType* _array;
	int _top;//表示有效元素个数  表示栈顶位置
	int _capacity;//底层空间的大小
}Stack;

//初始化
void StackInit(Stack* s);

// 检测栈是否为空 
int StackEmpty(Stack* s);

// 入栈 
void StackPush(Stack* s, DataType data);

// 出栈 
void StackPop(Stack* s);

// 获取栈顶元素 
DataType StackTop(Stack* s);

// 有效元素的个数 
int StackSize(Stack* s);

//打印栈
void PrintStack(Stack* s);

//增容 
void StackCapacity(Stack* s);

//括号匹配问题
int MatchBrackets(Stack* s, const char* pstr);

//后缀表达式求值
int RPN(Stack* s, const char* pstr);
int FindSpace(const char* pstr);


#endif //__STACK_H__


//Stack.c

#include"Stack.h"
#include<assert.h>
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>

void StackInit(Stack* s)
{
	assert(s);

	s->_top = 0;
	s->_capacity = 10;
	s->_array = (DataType *)malloc(sizeof(DataType)*s->_capacity);
	if (NULL == s->_array)
	{
		assert(s->_array);
		return;
	}
}

int StackEmpty(Stack* s)
{
	assert(s);

	if (s->_top)
		return 0;
	
	return 1;
}

void StackPush(Stack* s, DataType data)
{
	assert(s);

	//判断栈是否满了
	if (s->_top >= s->_capacity)
		StackCapacity(s);

	s->_array[s->_top++] = data;
}

void StackPop(Stack* s)
{
	assert(s);

	//动态栈为空
	if (StackEmpty(s))
		return;

	--s->_top;
}

DataType StackTop(Stack* s)
{
	assert(!StackEmpty(s));

	return s->_array[s->_top - 1];
}

int StackSize(Stack* s)
{
	assert(s);

	return s->_top;
}

void PrintStack(Stack* s)
{
	int i = 0;
	assert(s);

	//动态栈为空
	if (StackEmpty(s))
		return;

	if (0 == s->_top)
		return;

	for (i = 0; i < s->_top; ++i)
	{
		printf("%d ",s->_array[i]);
	}
	printf("\n");
}

void StackCapacity(Stack* s)
{
	assert(s);

	DataType * temp = s->_array;
	//动态栈为空
	if (StackEmpty(s))
		return;

	s->_array = (DataType *)realloc(s->_array, sizeof(DataType)*s->_capacity * 2);
	if (NULL == s->_array)
	{
		printf("增容失败");
		s->_array = temp;
	}

}

int MatchBrackets(Stack* s, const char* pstr)
{
	assert(s);

	int i = 0;
	int len = 0;
	len = strlen(pstr);
	if (NULL == pstr)
		return 0;
	for (i = 0; i < len; ++i)
	{
		if (pstr[i] == '(' || pstr[i] == ')' ||
			pstr[i] == '[' || pstr[i] == ']' ||
			pstr[i] == '{' || pstr[i] == '}')
		{
			if (pstr[i] == '(' || pstr[i] == '[' || pstr[i] == '{')
			{
				StackPush(s, pstr[i]);
			
			}

			if (pstr[i] == ')' || pstr[i] == ']' || pstr[i] == '}')
			{
				char str = 0;
				if (StackEmpty(s))
				{
					printf("右括号多余左括号\n");
					return 0;
				}

				str = StackTop(s);
				if (pstr[i] == ')' && str == '(' ||
					pstr[i] == ']' && str == '[' ||
					pstr[i] == '}' && str == '{')
				{
					StackPop(s);
				}
				else
				{
					printf("括号不匹配\n");
					return 0;
				}
			}
		}
		else
			continue;
		
	}

	if (!StackEmpty(s))
	{
		printf("左括号多余右括号\n");
		return 0;
	}

	printf("匹配正确\n");
	return 1;
}

int RPN(Stack* s, const char* pstr)
{
	int i = 0;
	int len = 0;
	int num = 0;
	len = strlen(pstr);
	assert(s);
	assert(pstr);

	for (i = 0; i < len; ++i)
	{
		int right = 0;
		int left = 0;
		if (pstr[i] >= '0' && pstr[i] <= '9')
		{
			StackPush(s, atoi(&pstr[i]));

			i = i + FindSpace(&pstr[i]);
			
		}
		else
		{
			if (' ' != pstr[i])
			{
				right = StackTop(s);
				StackPop(s);
				left = StackTop(s);
				StackPop(s);
			}

			switch (pstr[i])
			{
			case '+':
				StackPush(s, left + right);
				break;
			case '-':
				StackPush(s, left - right);
				break;
			case '*':
				StackPush(s, left * right);
				break;
			case '/':
			{	
				if (0 == right)
				{
					printf("分母不能为0\n");
					break;
	            }
				StackPush(s, left / right);
				break;
			}
			default:
				break;
			}
		}
	}
	return StackTop(s);
}

int FindSpace(const char* pstr)
{
	int i = 0;
	assert(pstr);

	while (' ' != pstr[i])
	{
		++i;
	}

	return i;
}


//test.c

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
