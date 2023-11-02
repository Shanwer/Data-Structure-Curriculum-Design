#include <cstdio>

#define MaxSize 100				//顺序栈的初始分配空间大小
typedef char ElemType;			//假设顺序栈中所有元素为char类型
typedef struct
{	char data[MaxSize];		//保存栈中元素
	int top;					//栈顶指针
}SqStack;

void initStack(SqStack &st);
void DestroyStack(SqStack st);
int push(SqStack &st,ElemType x);
int pop(SqStack &st,ElemType &x);
int getTop(SqStack st,ElemType &x);
bool isEmpty(SqStack st);