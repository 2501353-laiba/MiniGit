#pragma once

#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <string>
using namespace std;

class FileTask {
public:
    string taskType;
    string fileName;

    FileTask();
    FileTask(string type, string name);
};

class QueueNode {
public:
    FileTask task;
    QueueNode* next;

    QueueNode(FileTask t);
};

class TaskQueue {
private:
    QueueNode* front;
    QueueNode* rear;

public:
    TaskQueue();
    ~TaskQueue();

    void enqueue(FileTask task);
    FileTask dequeue();
    bool isEmpty();
    void clear();
};

#endif
