//
// Created by Shanwer on 2023/10/29.
//
#include <iostream>
#include <random>

using namespace std;

extern random_device rd;
extern default_random_engine engine;
//normal_distribution<> randomDouble(25,10); //正态分布模板类，均值为25，标准差为10，生成值默认为double
uniform_int_distribution<unsigned > randomNum(1,50);

// 生成随机整数
int generateRandomNumber(int min, int max) {
    return min + engine() % (max - min + 1);
}

// 生成随机运算符
char generateRandomOperator() {
    char operators[] = {'+', '-', '*', '/'};
    unsigned int index = engine() % 4;
    return operators[index];
}

// 生成随机数学表达式
string generateRandomExpression(int depth, int sign) {
    if (depth == 0) {
        // 生成随机整数作为操作数
        return to_string(randomNum(engine));
    } else {
        string expression;
        int generateParentheses = generateRandomNumber(0, 1); // 随机生成括号
        char op = generateRandomOperator(); // 随机生成运算符

        // 递归生成左右两个子表达式
        string left = generateRandomExpression(depth - 1, 0);
        string right = generateRandomExpression(depth - 1, 0);

        if (sign == 1){
            generateParentheses = 0;
        }

        if (generateParentheses > 0) {
            expression += "(";
        }

        expression += left;
        expression += " ";
        expression += op;
        expression += " ";
        expression += right;

        if (generateParentheses > 0) {
            expression += ")";
        }

        return expression;
    }
}