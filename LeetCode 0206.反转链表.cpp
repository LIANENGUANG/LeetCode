//
// Created by egl1an on 2023/10/6.
//
#include "predefs.h"

class ListNode {
public:
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}  // 默认构造函数，val 初始化为 0，next 初始化为 nullptr

    ListNode(int val) : val(val), next(nullptr) {}  // 一个参数的构造函数，val 被初始化，next 初始化为 nullptr

    ListNode(int val, ListNode *next) : val(val), next(next) {}  // 两个参数的构造函数
};
// 右值总是等于左值，左值不可改变
// 右值是短暂的，没有持久的存储位置，而左值代表了存储在内存中的对象

class Solution {
public:
    ListNode *reverseList(ListNode *head) {
        ListNode *last = nullptr;
        ListNode *curr = head;
        while (curr != nullptr) {
            //存储临时的当前的下一个节点
            ListNode *next = curr->next;
            // 将当前节点指向反转链表首节点
            curr->next = last;
            // 更新反转链表的首节点
            last = curr;
            // 更新当前节点到下一个节点
            curr = next;
        }
        return last;
    }
};

int main206() {
    ListNode *node1 = new ListNode(1);
    ListNode *node2 = new ListNode(2);
    ListNode *node3 = new ListNode(3);
    ListNode *node4 = new ListNode(4);
    ListNode *node5 = new ListNode(5);

    // 连接各个节点
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    Solution sol;

    ListNode *tmp = sol.reverseList(node1);

    // 输出反转后的链表
    while (tmp != nullptr) {
        cout << tmp->val << " -> ";
        tmp = tmp->next;
    }
    cout << "nullptr" << endl;
}
