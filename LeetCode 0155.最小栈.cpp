//
// Created by egl1an on 2023/10/6.
//
// 记录往栈的最深处走的过程中的最小值
// 底层仍旧是栈
// 历史栈用于维护历史最小值而不至于丢失
#include "predefs.h"

class MinStack {
public:
    MinStack() {

    }

    void push(int val) {
        s.push(val);
        if (preMin.empty()) preMin.push(val);
        else preMin.push(min(preMin.top(), val));

    }

    // 记忆的和当前的一起推出最小值，此时最小值就是preMin的栈顶，这么做是为了记忆之前的最小值而不至于丢失
    void pop() {
        s.pop();
        preMin.pop();

    }

    int top() {
        return s.top();
    }

    int getMin() {
        return preMin.top();

    }

private:
    stack<int> s;
    stack<int> preMin;
};

int main155() {
    MinStack minStack;

    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    cout << "Minimum in stack: " << minStack.getMin() << endl;   // should return -3
    minStack.pop();
    cout << "Top of stack: " << minStack.top() << endl;         // should return 0
    cout << "Minimum in stack: " << minStack.getMin() << endl;   // should return -2

    return 0;
}
/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */