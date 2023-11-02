//
// Created by Shanwer on 2023/10/31.
//

#include "SqCharStack.h"

void initStack(SqStack &st)		//st为引用型参数
{
    st.top=-1;
}
void DestroyStack(SqStack st)
{    }

int push(SqStack &st,ElemType x)
{	if (st.top==MaxSize-1) {    //栈满
        return 0;
    } else {
        st.top++;
        st.data[st.top]=x;
        return 1;
    }
}

int pop(SqStack &st,ElemType &x)	//x为引用型参数
{
    if (st.top == -1) {                    //栈空
        return 0;
    } else {
        x = st.data[st.top];
        st.top--;
        return 1;
    }
}

int getTop(SqStack st,ElemType &x)	//x为引用型参数
{
    if (st.top == -1) {                    //栈空
        return 0;
    } else {
        x = st.data[st.top];
        return 1;
    }
}

void printAll(SqStack st){
    for(int i = st.top; i!=-1;i--){
        printf("%c\n",st.data[i]);
    }//破坏了栈的定义，调试用
}

bool isEmpty(SqStack st)
{
    if (st.top != -1)
        return false;
    else
        return true;
}