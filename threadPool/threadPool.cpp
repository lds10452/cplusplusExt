#include"ThreadPool.h"
ThreadPool::ThreadPool() :done(false), isEmpty(true), isFull(false) {
}

//���ó��г�ʼ�߳���
void ThreadPool::setSize(int num) {
    (*this).initnum = num;
}

//�������
void ThreadPool::addTask(const Task& f) {

    if (!done) {
        //����������Դ    
        unique_lock<mutex>lk(_mutex);
        //Ҫ�����������������,�͵ȴ������������
        while (isFull) {
            cond.wait(lk);
        }

        //���������������
        task.push(f);

        if (task.size() == initnum)
            isFull = true;

        cout << "Add a task" << endl;
        isEmpty = false;
        cond.notify_one();
    }
}

void ThreadPool::finish() {

    //�̳߳ؽ�������
    for (size_t i = 0; i < threads.size(); i++) {
        threads[i].join();
    }
}

void ThreadPool::runTask() {

    //���ϱ�������,�ж�Ҫ��������Ļ�,��ִ��
    while (!done) {
        cout << "wait   "<<order << endl;
        unique_lock<mutex>lk(_mutex);

        //����Ϊ�յĻ�,�͵ȴ�����
        while (isEmpty) {
            cond.wait(lk);
        }

        Task ta;
        //ת�ƿ��ƿ�,����ֵ����ת��Ϊ��ֵ����
        ta = move(task.front());
        task.pop();

        if (task.empty()) {
            isEmpty = true;
        }
        //cout << "pop a task"<< endl;
        isFull = false;
        ta();
        //cout << "finish a task" << endl;
        cond.notify_one();
    }
}

void ThreadPool::start(int num) {

    setSize(num);

    for (int i = 0; i < num; i++) {
        threads.push_back(thread(&ThreadPool::runTask, this));
    }
}
ThreadPool::~ThreadPool() {
}
