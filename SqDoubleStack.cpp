//
// Created by Shanwer on 2023/10/31.
//

#include "SqDoubleStack.h"

void initDoubleStack(SqStack &st)		//st为引用型参数
{
    st.top=-1;
}
void DestroyDoubleStack(SqStack st)
{    }

int pushDoubleStack(SqStack &st, ElemType x)
{	if (st.top==MaxSize-1) {    //栈满
        return 0;
    } else {
        st.top++;
        st.data[st.top]=x;
        return 1;
    }
}

int popDoubleStack(SqStack &st, ElemType &x)	//x为引用型参数
{
    if (st.top == -1) {                    //栈空
        return 0;
    } else {
        x = st.data[st.top];
        st.top--;
        return 1;
    }
}

int getDoubleStackTop(SqStack st, ElemType &x)	//x为引用型参数
{
    if (st.top == -1) {                    //栈空
        return 0;
    } else {
        x = st.data[st.top];
        return 1;
    }
}

void printAllDoubleStack(SqStack st){
    for(int i = st.top; i!=-1;i--){
        printf("%c\n",st.data[i]);
    }//破坏了栈的定义，调试用
}

bool doubleStackIsEmpty(SqStack st)
{
    if (st.top != -1)
        return false;
    else
        return true;
}