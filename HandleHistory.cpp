//
// Created by Shanwer on 2023/11/1.
//
#include <iostream>
#include <fstream>
#include <chrono>
#include "HandleHistory.h"

using namespace std;

typedef struct{
    int id;
    int score;
    unsigned int questNum;
    string time;
}score;

bool saveScore(int correctTimes, unsigned int questNum){
    ifstream ifs;
    ifs.open("score.txt", ios::in);//I believe myself so no further checks will be made.
    int lineCount = 1;

    string aline;
    while(getline(ifs,aline)){
        lineCount++;
    }
    ifs.close();
    // 获取当前时间点
    auto now = std::chrono::system_clock::now();

    // 转换为time_t以便能以年月日的形式输出
    std::time_t now_c = std::chrono::system_clock::to_time_t(now);

    score presentScore{
        .id =  lineCount,
        .score = correctTimes,
        .questNum = questNum,
        .time = std::ctime(&now_c),
    };
    fstream fs;
    fs.open("score.txt", ios::app);
    fs << presentScore.id << " " << presentScore.score << " " << presentScore.questNum << " "<< presentScore.time;
    fs.close();
    return true;
}

int findHighest(){
    ifstream ifs;
    ifs.open("score.txt", ios::in);
    string aline;
    int highest = 0;
    if(ifs.peek() == EOF){
        //成绩文件存在但为空则返回-1，防止逻辑判断错误
        return -1;
    }
    while(getline(ifs,aline)){
        string intString;
        int startIndex, endIndex;
        bool sign = false;
        for(int i = 0; ; i++){
            if(aline[i] == ' ' && sign){
                endIndex = i+1;
                break;
            }else if(aline[i] == ' '){
                startIndex = i+1;
                sign = true;
            }
        }
        highest = max(highest,stoi(aline.substr(startIndex,endIndex-startIndex)));
    }
    return highest;
}

void traverseScoreFile(){
    ifstream ifs;
    ifs.open("score.txt", ios::in);
    string aline;
    while(getline(ifs,aline)){
        cout << "ID\t答对题目 总题目\t时间" << endl;
        int sign = 0;
        for(int i = 0 ; i<aline.length(); i++){
            if(aline[i]==' ' && sign < 3){
                aline.insert(i,1,'\t');
                i++;
                sign++;
            }
        }
        cout << aline << endl;
    }
}