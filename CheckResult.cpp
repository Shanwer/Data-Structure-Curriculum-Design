//
// Created by Shanwer on 2023/10/31.
//

//This will not be complied either, only included in handleRequest.cpp(otherwise it will got multiply definition of function)
#include <string>
#include <iostream>
#include <type_traits>
#include "SqDoubleStack.h"

using namespace std;

double calculateResult(const std::string rpn) {
    double result;
    SqStack stack;
    initDoubleStack(stack);
    string anDoubleString;
    for(char c: rpn){
        if(isdigit(c)){
            anDoubleString += c;
        }else if (c == ' ' && !anDoubleString.empty()){
            pushDoubleStack(stack, stod(anDoubleString));//�����ǰû���ϸ����沨�����ʽ���ɵ�����ո�������ͻ���鷳
            anDoubleString= "";
        }else if (c == ' ') {
            continue;
        }else{
            double a,b;
            popDoubleStack(stack, b);
            popDoubleStack(stack, a);
            switch(c){
                case '*':{
                    result = a * b;
                    pushDoubleStack(stack,result);
                    break;
                }
                case '/':{
                    result = a / b;
                    pushDoubleStack(stack,result);
                    break;
                }
                case '+':{
                    result = a + b;
                    pushDoubleStack(stack,result);
                    break;
                }
                case '-':{
                    result = a - b;
                    pushDoubleStack(stack,result);
                    break;
                }
                default:{
                    std::cout << "������������ַ�:" << c << endl;
                    std::cout << "������һ����������� > <" << endl;
                }
            }
        }
    }
    popDoubleStack(stack,result);
    DestroyDoubleStack(stack);
    return result;
}

template <typename T>
bool checkResult(T result, double calculatedResult){//TODO:����������������
#ifndef NDEBUG
    cout << "ϵͳ������Ϊ:" + to_string(std::round(calculatedResult * 100) / 100) << endl;
#endif
    if(std::is_same<T, int>::value){
        if(result == (int)calculatedResult)
            return true;
    }else if(std::is_same<T, double>::value){
        if(abs((result - std::round(calculatedResult * 100) / 100)) < 0.00001)//TODO:����
            return true;
    }
    return false;

}
