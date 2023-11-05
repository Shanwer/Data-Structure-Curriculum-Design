//
// Created by Shanwer on 2023/10/29.
//
#include <iostream>
#include <string>
#include <random>
#include "GenerateArithmeticExpression.h"
#include "CheckResult.cpp"
#include "ConvertToRPN.h"
#include "HandleHistory.h"

using namespace std;

extern random_device rd;
extern default_random_engine engine;
uniform_int_distribution<unsigned> expressionDepth(1,3);
uniform_int_distribution<unsigned> randomQuest(1,20);

bool generateQuest(int correctTimes,unsigned int questNum) {
    string rawString;
    //handledString;

    unsigned int randomDepth = expressionDepth(engine);
    if (randomDepth == 1 || randomDepth == 3) {
        rawString = generateRandomExpression(randomDepth, 1);
    } else {
        rawString = generateRandomExpression(randomDepth, 0);
    }

    /*if ((rawString[0] == '(' && rawString[1] == '(') &&
        (rawString[rawString.length() - 1] == ')' && rawString[rawString.length() - 2] == ')')) {
        handledString = rawString.substr(1, rawString.length() - 2);
    } else {
        handledString = rawString;
    }
     * 这个算法似乎有问题
     */
    //上述检查都是为了减少随机生成的重复括号，sign参数为1时，函数在当前深度进行递归时就不进行向表达式随机加入括号的操作
    //handledString = rawString;
    cout << "请计算:" + rawString << endl;
#ifndef NDEBUG
    cout << "生成的RPN:" + convertToRPN(handledString) << endl;
#endif
    int retryTime = 1;
    double calculatedResult = calculateResult(convertToRPN(rawString));
    retry:
    string inputResult;
    cin >> inputResult;

    try {
        double doubleResult = stod(inputResult);//如果不为浮点就捕获异常转为整型
        if (checkResult<double>(doubleResult, calculatedResult)) {
            cout << "结果正确" << endl;
            return true;
        } else if (retryTime != 0) {
            cout << "结果错误，再试一次吧" << endl;
            retryTime = 0;
            goto retry;
        } else {
            cout << "结果错误" << endl;
            return false;
        }
    } catch (const invalid_argument &) {
        try {
            int intResult = stoi(inputResult);
            if (checkResult<int>(intResult, calculatedResult)) {
                cout << "结果正确" << endl;
                return true;
            } else if (retryTime != 0) {
                cout << "结果错误，再试一次吧" << endl;
                retryTime = 0;
                goto retry;
            }else {
                cout << "结果错误" << endl;
                return false;
            }
        } catch (const invalid_argument &) {
            if(inputResult == "wq"){
                cout << "保存并退出中...";
                saveScore(correctTimes,questNum);
                exit(0);
            }else{
                cout << "输入内容错误，只能输入数字和wq指令哦" << endl;
                goto retry;
            }
        }
    }
}

void handleQuery(int input){
    unsigned int questNum;
    int correctTimes = 0;
    int highest = findHighest();
    switch(input){
        case 1:
            cout << "输入想要的题目数量:";
            cin >> questNum;
            for(unsigned int i = questNum; i > 0; i --){
                if(generateQuest(correctTimes,questNum)){
                    correctTimes ++;
                }
            }
            saveScore(correctTimes,questNum);

            if(highest <= correctTimes){
                cout << "你上次最多做出了:"  << highest << "道题！" << endl;
                cout << "做的比上次还多，真不错，再接再厉!" << endl;
            }else if(highest == -1){
                break;
            }else{
                cout << "你上次最多做出了:"  << highest << "道题！" << endl;
                cout << "做的没有上次多，但也没关系，下次加油!" << endl;
            }
            break;
        case 2:
            questNum = randomQuest(engine);
            cout << "随机生成了:" << questNum << "道题目" << endl;
            for(unsigned int i = questNum; i > 0; i --) {
                if(generateQuest(correctTimes,questNum)){
                    correctTimes ++;
                }
            }
            saveScore(correctTimes,questNum);

            if(highest <= correctTimes){
                cout << "你上次最多做出了:"  << highest << "道题！" << endl;
                cout << "做的比上次还多，真不错，再接再厉!" << endl;
            }else if(highest == -1){
                break;
            }else{
                cout << "你上次最多做出了:"  << highest << "道题！" << endl;
                cout << "做的没有上次多，但也没关系，下次加油!" << endl;
            }

            break;
        case 3:
            if(highest==-1){
                cout<< "你还没写呢，先去写几道题存个记录吧！"<<endl;
            }else {
                cout << "你的最好成绩一共做出了:" << highest << "道题！" << endl;
            }
            break;
        case 4:
            traverseScoreFile();
            break;
        default:
        case 9:
            cout << "退出";
            break;
    }
}

