#include <iostream>
#include <deque>
#include <thread>
#include <mutex>
#include <condition_variable>
#include<Windows.h>
using namespace std;

deque<int> q;
mutex mu;
condition_variable cond;
int c = 0;//�������Ĳ�Ʒ����

void producer() {
	int data1;
	while (1) {//ͨ�����ѭ�����ܱ�֤�����ò�ֹͣ
		if (c < 3) {//����
			{
				data1 = rand();
				unique_lock<mutex> locker(mu);//��
				q.push_front(data1);
				cout << "����" << data1 << endl;
				cond.notify_one();  // ֪ͨȡ
				++c;
			}
			Sleep(500);
		}
	}
}

void consumer() {
	int data2;//data�������Ǵ��ȡ������
	while (1) {
		{
			unique_lock<mutex> locker(mu);
			while (q.empty())
				cond.wait(locker); //wati()����ǰ�Ȼ����,�����������߲��ܻ�������Ų�Ʒ����������������notify�󣬽��������������Զ��ֻ��������
			data2 = q.back();//ȡ�ĵ�һ��
			q.pop_back();//ȡ�ĵڶ���
			cout << "" << data2 << endl;
			--c;
		}
		Sleep(1500);
	}
}
int main() {
	thread t1(producer);
	thread t2(consumer);
	t1.join();
	t2.join();
	system("pause");
	return 0;
}