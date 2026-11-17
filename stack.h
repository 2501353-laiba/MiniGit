#ifndef STACK_H
#define STACK_H
#include <iostream>
#include <string>
using namespace std;
class StackNode {
public:
    string commitID;
    StackNode* next;
    StackNode(string id);
};
class CheckoutStack {
private:
    StackNode* top;
public:
    CheckoutStack();
    ~CheckoutStack();
    void push(string commitID);
    string pop();
    string peek();
    bool isEmpty();
    void clear();
};
#endif
