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
     * ����㷨�ƺ�������
     */
    //������鶼��Ϊ�˼���������ɵ��ظ����ţ�sign����Ϊ1ʱ�������ڵ�ǰ��Ƚ��еݹ�ʱ�Ͳ���������ʽ����������ŵĲ���
    //handledString = rawString;
    cout << "�����:" + rawString << endl;
#ifndef NDEBUG
    cout << "���ɵ�RPN:" + convertToRPN(handledString) << endl;
#endif
    int retryTime = 1;
    retry:
    string inputResult;
    cin >> inputResult;

    try {
        double doubleResult = stod(inputResult);//�����Ϊ����Ͳ����쳣תΪ����
        if (checkResult<double>(doubleResult, calculateResult(convertToRPN(rawString)))) {
            cout << "�����ȷ" << endl;
            return true;
        } else if (retryTime != 0) {
            cout << "�����������һ�ΰ�" << endl;
            retryTime = 0;
            goto retry;
        } else {
            cout << "�������" << endl;
            return false;
        }
    } catch (const invalid_argument &) {
        try {
            int intResult = stoi(inputResult);
            if (checkResult<int>(intResult, calculateResult(convertToRPN(rawString)))) {
                cout << "�����ȷ" << endl;
                return true;
            } else if (retryTime != 0) {
                cout << "�����������һ�ΰ�" << endl;
                retryTime = 0;
                goto retry;
            }else {
                cout << "�������" << endl;
                return false;
            }
        } catch (const invalid_argument &) {
            if(inputResult == "wq"){
                cout << "���沢�˳���...";
                saveScore(correctTimes,questNum);
                exit(0);
            }else{
                cout << "�������ݴ���ֻ���������ֺ�wqָ��Ŷ" << endl;
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
            cout << "������Ҫ����Ŀ����:";
            cin >> questNum;
            for(unsigned int i = questNum; i > 0; i --){
                if(generateQuest(correctTimes,questNum)){
                    correctTimes ++;
                }
            }
            saveScore(correctTimes,questNum);

            if(highest >= correctTimes){
                cout << "���ϴ����������:"  << highest << "���⣡" << endl;
                cout << "���ı��ϴλ��࣬�治���ٽ�����!" << endl;
            }else if(highest == -1){
                break;
            }else{
                cout << "���ϴ����������:"  << highest << "���⣡" << endl;
                cout << "����û���ϴζ࣬��Ҳû��ϵ���´μ���!" << endl;
            }
            break;
        case 2:
            questNum = randomQuest(engine);
            cout << "���������:" << questNum << "����Ŀ" << endl;
            for(unsigned int i = questNum; i > 0; i --) {
                if(generateQuest(correctTimes,questNum)){
                    correctTimes ++;
                }
            }
            saveScore(correctTimes,questNum);

            if(highest >= correctTimes){
                cout << "���ϴ����������:"  << highest << "���⣡" << endl;
                cout << "���ı��ϴλ��࣬�治���ٽ�����!" << endl;
            }else if(highest == -1){
                break;
            }else{
                cout << "���ϴ����������:"  << highest << "���⣡" << endl;
                cout << "����û���ϴζ࣬��Ҳû��ϵ���´μ���!" << endl;
            }

            break;
        case 3:
            if(highest==-1){
                cout<< "�㻹ûд�أ���ȥд����������¼�ɣ�"<<endl;
            }else {
                cout << "�����óɼ�һ��������:" << highest << "���⣡" << endl;
            }
            break;
        case 4:
            traverseScoreFile();
            break;
        default:
        case 9:
            cout << "�˳�";
            break;
    }
}

