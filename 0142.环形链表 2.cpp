//
// Created by egl1an on 2023/10/6.
//
#include "predefs.h"
struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (!head || !head->next) return nullptr;  // 如果链表为空或只有一个节点，直接返回nullptr

        ListNode *slow = head, *fast = head;  // 初始化快慢两个指针

        // Step 1: 使用Floyd的环检测算法检查是否存在环
        bool hasCycle = false;
        while (fast && fast->next) {  // 当快指针和它的下一个都不为空时
            slow = slow->next;  // 慢指针走一步
            fast = fast->next->next;  // 快指针走两步
            if (slow == fast) {  // 如果快慢指针相遇，说明存在环
                hasCycle = true;
                break;
            }
        }

        // 如果没有环，返回nullptr
        if (!hasCycle) return nullptr;

        // Step 2: 检测环的起始点
        // 原理是同余关系这意味着从链表的起始点到环的起始点的距离（a）等于从相遇点回到环的起始点的距离（c）。
        // 这就是为什么我们将慢指针重置为链表的起始点，然后移动两个指针，每次各移动一步，它们最终会在环的起始点相遇的原因。
        slow = head;  // 将慢指针重新置为链表头部
        while (slow != fast) {  // 当慢指针和快指针不相遇时
            slow = slow->next;  // 两个指针都各走一步
            fast = fast->next;
        }

        return slow;  // 返回环的起始节点
    }
};
int main142() {
    // 创建链表: 1 -> 2 -> 3 -> 4 -> 2 ...
    // 注意: 这只是为了演示。实际上，我们不应该创建这样的循环，因为这会导致不良的内存管理行为。
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);
    ListNode* node4 = new ListNode(4);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node2;  // 创建环，使4指回2

    Solution solution;
    ListNode* cycleStart = solution.detectCycle(node1);

    if (cycleStart) {
        std::cout << "环的起始点的值为: " << cycleStart->val << std::endl;
    } else {
        std::cout << "链表中没有环." << std::endl;
    }

    // 清理内存。注意：因为链表有环，所以不能简单地删除每个节点，否则会陷入无限循环。
    // 在这种情况下，一个简单的方法是首先断开环，然后再逐个删除节点。
    node4->next = nullptr;
    delete node1;
    delete node2;
    delete node3;
    delete node4;

    return 0;
}