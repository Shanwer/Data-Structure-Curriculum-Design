#include <cstdio>

#define MaxSize 100				//˳��ջ�ĳ�ʼ����ռ��С
typedef double ElemType;			//����˳��ջ������Ԫ��Ϊchar����
typedef struct
{	ElemType data[MaxSize];		//����ջ��Ԫ��
	int top;					//ջ��ָ��
} SqStack;

void initDoubleStack(SqStack &st);
void DestroyDoubleStack(SqStack st);
int pushDoubleStack(SqStack &st, ElemType x);
int popDoubleStack(SqStack &st, ElemType &x);
int getDoubleStackTop(SqStack st, ElemType &x);
bool doubleStackIsEmpty(SqStack st);