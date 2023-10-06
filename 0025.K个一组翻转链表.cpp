#include "predefs.h"

class ListNode {
public:
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}  // 默认构造函数，val 初始化为 0，next 初始化为 nullptr

    ListNode(int val) : val(val), next(nullptr) {}  // 一个参数的构造函数，val 被初始化，next 初始化为 nullptr

    ListNode(int val, ListNode *next) : val(val), next(next) {}  // 两个参数的构造函数
};

class Solution {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        if (!head || k <= 1) return head;  // Edge cases

        int len = getLength(head);
        ListNode *dummy = new ListNode(0, head);
        ListNode *prev = dummy;

        while (len >= k) {
            ListNode *groupTail = getKthNode(prev, k);  // Find the end of the group to be reversed
            //if (!groupTail) 的含义就是：如果 groupTail 是一个空指针（即它不指向任何有效的节点），则执行该条件语句。
            // 不加感叹号是条件非空则执行函数体，而加感叹号是条件空则执行函数体
            if (!groupTail) break;
            // 当前组头
            ListNode *groupHead = prev->next;
            // 下一组头等于当前组的结尾的下一个节点
            ListNode *nextGroupHead = groupTail->next;
            // 根据当前组头和尾指针反转部分链表
            reverse(groupHead, groupTail);
            // 将前一组
            prev->next = groupTail;
            groupHead->next = nextGroupHead;

            prev = groupHead;
            len -= k;
        }

        return dummy->next;
    }

private:
    int getLength(ListNode *head) {
        int len = 0;
        while (head) {
            len++;
            head = head->next;
        }
        return len;
    }

    // Get the kth node after 'node'. Returns nullptr if not available.
    ListNode* getKthNode(ListNode* node, int k) {
        while (k-- && node) {
            node = node->next;
        }
        return node;
    }

    void reverse(ListNode* start, ListNode* end) {
        ListNode *prev = nullptr;
        ListNode *curr = start;
        while (curr != end) {
            ListNode *next = curr->next;
            curr->next = prev ? prev : end->next;  // Attach to previous node or the original tail's next
            prev = curr;
            curr = next;
        }
        end->next = prev;  // Attach the original tail to the last reversed node
    }
};


