#include "Stack.h"
StackNode::StackNode(string id) {
    commitID = id;
    next = nullptr;
}
CheckoutStack::CheckoutStack() {
    top = nullptr;
}
bool CheckoutStack::isEmpty() {
    return top == nullptr;
}
void CheckoutStack::push(string commitID) {
    StackNode* newNode = new StackNode(commitID);
    newNode->next = top;
    top = newNode;
    cout << "Commit ID pushed into Stack successfully!\n";
}
string CheckoutStack::pop() {
    if (isEmpty()) {
        cout << "Stack is empty!\n";
        return "";
    }
    StackNode* temp = top;
    string id = temp->commitID;
    top = top->next;
    delete temp;
    return id;
}
string CheckoutStack::peek() {
    if (isEmpty()) {
        cout << "Stack is empty!\n";
        return "";
    }
    return top->commitID;
}
Page 5
Mini Git — Team Workflow & Ready-to-Paste Code
void CheckoutStack::clear() {
    while (!isEmpty()) {
        pop();
    }
}
CheckoutStack::~CheckoutStack() {
    clear();
}
