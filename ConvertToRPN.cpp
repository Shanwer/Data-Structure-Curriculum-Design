//
// Created by Shanwer on 2023/10/31.
//

#include <string>
#include "SqCharStack.h"

using namespace std;

// 判断字符是否为运算符
bool isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

// 判断运算符的优先级
int getPriority(char op) {
    if (op == '+' || op == '-') {
        return 1;
    } else if (op == '*' || op == '/') {
        return 2;
    }
    return 0;
}

// 将普通四则运算算式转换成逆波兰表达式
string convertToRPN(string expression) {
    SqStack operators; // 运算符栈
    string rpn; // 逆波兰表达式字符串
    initStack(operators);
    char topChar; //存放栈顶字符的临时变量

    for (char ch : expression) {
        if (isdigit(ch)) { // 如果是数字则直接拼接到rpn字符串
            rpn += ch;
            continue;
        } else if (isOperator(ch)) { // 如果遍历表达式的字符是运算符
            getTop(operators,topChar);
            while (!isEmpty(operators) && isOperator(topChar) &&
                   getPriority(ch) <= getPriority(topChar)) { //并且栈非空，栈顶为二元运算符并且遍历字符优先级低于栈顶字符
                if(rpn[rpn.length()-1] != ' '){
                    rpn += ' ';
                }
                rpn += topChar;
                pop(operators, topChar);
                getTop(operators,topChar); //更新循环检测条件的变量，下面检测右括号时同理
            }
            push(operators,ch); //否则仅将遍历字符入栈
        } else if (ch == '(') {
            push(operators,ch);
        } else if (ch == ')') {
            getTop(operators,topChar);
            while (!isEmpty(operators) && topChar != '(') {
                rpn += ' ';
                rpn += topChar;
                pop(operators,topChar);
                getTop(operators,topChar);
            }
            pop(operators,topChar); // 弹出左括号
        } else if (ch == ' ' && rpn[(rpn.length()-1)] != ' '){
            rpn += ' ';
        }
    }

    // 将剩余的运算符输出
    while (!isEmpty(operators)) {
        getTop(operators,topChar);
        rpn += ' ';
        rpn += topChar;
        pop(operators,topChar);
    }
    DestroyStack(operators);
    return rpn;
}
