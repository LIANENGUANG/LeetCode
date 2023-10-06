#include "predefs.h"

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

// 快慢指针法，有环的化快指针和慢指针会套圈
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            // 快指针一次走两步
            fast = fast->next->next;
            // 慢指针一次走一步
            head = head->next;
            if (fast == head) {
                return true;
            }

        }return false;
    }
};
int main141() {
    // Create nodes
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);
    ListNode* node4 = new ListNode(4);

    // Link nodes to create a list: 1 -> 2 -> 3 -> 4
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;

    // Check for cycle
    Solution solution;
    if (solution.hasCycle(node1)) {
        std::cout << "The linked list has a cycle." << std::endl;
    } else {
        std::cout << "The linked list doesn't have a cycle." << std::endl;
    }

    // Introduce a cycle: 4 -> 2 (This will make the linked list circular)
    node4->next = node2;

    // Check again for cycle
    if (solution.hasCycle(node1)) {
        std::cout << "The linked list has a cycle." << std::endl;
    } else {
        std::cout << "The linked list doesn't have a cycle." << std::endl;
    }

    // Cleanup (Note: This step is tricky since we introduced a cycle. Avoid deallocating memory in a circular linked list.)
    delete node1;
    delete node2;
    delete node3;
    delete node4;

    return 0;
}