//
// Created by Shanwer on 2023/10/29.
//

#include <iostream>
#include <random>
#include "HandleRequest.h"

using namespace std;

random_device rd;
default_random_engine engine{rd()};

int main(){

    cout << "欢迎使用四则运算练习器，请选择要使用的功能" <<endl;
    cout << "输入数字(1,2,3...)来选择功能" << endl;
    cout << "1. 选择指定数量的题目" << endl;
    cout << "2. 选择随机数量的题目(20道以内)" << endl;
    cout << "3. 查看历史最高分数" << endl;
    cout << "4. 查看全部历史成绩" << endl;
    cout << "9. 退出(或输入其他数字)" << endl;
    cout << "PS:生成的算式各数字均在50以内，如果结果为小数，保留两位，计算错误有一次重试机会，回答问题输入wq的时候可以直接保存成绩并退出" << endl;
    cout << "PPS:问题未全部完成就退出会把剩下的题目视作答错" <<endl;
    cout << "请输入数字:";

    handleQuery(cin.get()-'0');//char类型数字 - char类型数字算出int

}