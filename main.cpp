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

    cout << "��ӭʹ������������ϰ������ѡ��Ҫʹ�õĹ���" <<endl;
    cout << "��������(1,2,3...)��ѡ����" << endl;
    cout << "1. ѡ��ָ����������Ŀ" << endl;
    cout << "2. ѡ�������������Ŀ(20������)" << endl;
    cout << "3. �鿴��ʷ��߷���" << endl;
    cout << "4. �鿴ȫ����ʷ�ɼ�" << endl;
    cout << "9. �˳�(��������������)" << endl;
    cout << "PS:���ɵ���ʽ�����־���50���ڣ�������ΪС����������λ�����������һ�����Ի��ᣬ�ش���������wq��ʱ�����ֱ�ӱ���ɼ����˳�" << endl;
    cout << "PPS:����δȫ����ɾ��˳����ʣ�µ���Ŀ�������" <<endl;
    cout << "����������:";

    handleQuery(cin.get()-'0');//char�������� - char�����������int

}