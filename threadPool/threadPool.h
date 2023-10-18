#pragma once

#include <iostream>
#include<stdlib.h>
#include<thread>
#include<mutex>
#include<condition_variable>
#include<vector>
#include<functional>
#include<queue>
#define N 10
using namespace std;
class ThreadPool {

public:
    //�Զ���void()�ĺ�������
    typedef function<void()>Task;

    ThreadPool();
    ~ThreadPool();

public:
    int order;
    size_t initnum;
    //�߳�����
    vector<thread>threads;

    //�������
    queue<Task>task;

    //��������������
    mutex _mutex;
    condition_variable cond;

    //�̳߳ع�������ʱΪ��
    bool done;

    //�����Ƿ�Ϊ��
    bool isEmpty;
    //�����Ƿ�Ϊ��
    bool isFull;

public:
    void addTask(const Task& f);
    void start(int num);
    void setSize(int num);
    void runTask();
    void finish();
};
