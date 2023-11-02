#include <cstdio>

#define MaxSize 100				//˳��ջ�ĳ�ʼ����ռ��С
typedef char ElemType;			//����˳��ջ������Ԫ��Ϊchar����
typedef struct
{	char data[MaxSize];		//����ջ��Ԫ��
	int top;					//ջ��ָ��
}SqStack;

void initStack(SqStack &st);
void DestroyStack(SqStack st);
int push(SqStack &st,ElemType x);
int pop(SqStack &st,ElemType &x);
int getTop(SqStack st,ElemType &x);
bool isEmpty(SqStack st);