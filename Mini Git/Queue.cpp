//This is Queue.cpp file

#include "Queue.h"

FileTask::FileTask() {
    taskType = "";
    fileName = "";
}

FileTask::FileTask(string type, string name) {
    taskType = type;
    fileName = name;
}

QueueNode::QueueNode(FileTask t) {
    task = t;
    next = nullptr;
}

TaskQueue::TaskQueue() {
    front = nullptr;
    rear = nullptr;
}

bool TaskQueue::isEmpty() {
    return front == nullptr;
}

void TaskQueue::enqueue(FileTask task) {
    QueueNode* newNode = new QueueNode(task);

    if (isEmpty()) {
        front = newNode;
        rear = newNode;
    }
    else {
        rear->next = newNode;
        rear = newNode;
    }

    cout << "Task added to Queue successfully!\n";
}

FileTask TaskQueue::dequeue() {
    if (isEmpty()) {
        cout << "Queue is empty!\n";
        return FileTask();
    }

    QueueNode* temp = front;
    FileTask removedTask = temp->task;

    front = front->next;

    if (front == nullptr) {
        rear = nullptr;
    }

    delete temp;
    return removedTask;
}

void TaskQueue::clear() {
    while (!isEmpty()) {
        dequeue();
    }
}

TaskQueue::~TaskQueue() {
    clear();
}
