#include <cstdio>

#define MaxSize 100				//顺序栈的初始分配空间大小
typedef double ElemType;			//假设顺序栈中所有元素为char类型
typedef struct
{	ElemType data[MaxSize];		//保存栈中元素
	int top;					//栈顶指针
} SqStack;

void initDoubleStack(SqStack &st);
void DestroyDoubleStack(SqStack st);
int pushDoubleStack(SqStack &st, ElemType x);
int popDoubleStack(SqStack &st, ElemType &x);
int getDoubleStackTop(SqStack st, ElemType &x);
bool doubleStackIsEmpty(SqStack st);