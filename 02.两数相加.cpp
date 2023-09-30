/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

//ListNode() : val(0), next(nullptr) {}
//这是一个默认构造函数。当你创建一个ListNode对象而不传递任何参数时，它会被调用。
//这个构造函数会将val初始化为0，并将next初始化为nullptr，即指向空的指针。

//ListNode(int x) : val(x), next(nullptr) {}
//这是一个接受一个整数参数的构造函数。当你创建一个ListNode对象并只传递一个整数时，这个构造函数会被调用。
//它会将val初始化为你传递的值，并将next初始化为nullptr。

//ListNode(int x, ListNode *next) : val(x), next(next) {}
//这是一个接受两个参数的构造函数：一个整数和一个ListNode指针。
// 当你创建一个ListNode对象并传递一个整数和一个ListNode指针时，这个构造函数会被调用。
// 它会将val初始化为你传递的整数，并将next初始化为你传递的ListNode指针。

//ListNode* newHead = new ListNode(0);
//这行代码创建了一个新的ListNode对象，其值(val)被初始化为0。
//使用new关键字在堆上为新对象分配空间，并返回该对象的指针。
//这个指针被保存在名为newHead的变量中。
//ListNode* cur = newHead;
//这行代码声明了一个新的指针变量名为cur（通常用于代表"current node"）。
//它初始化为与newHead指向的同一个ListNode对象，这意味着cur和newHead都指向同一个链表节点，那就是我们刚刚创建的那个节点。
//这样的代码结构通常在处理链表时非常有用，特别是当你需要构建一个新的链表并保留对链表头的引用。
//newHead通常用于保持对新链表的头部的引用，而cur指针用于遍历和修改链表，例如，向链表添加新节点。
//这种方法的好处是，在构建链表的过程中，你可以移动cur指针，而newHead始终保持对链表头部的引用.
//这样在链表构建完成后，你仍然可以访问整个链表。



//l1:
//指向第一个输入链表的当前节点。
//用于遍历并读取第一个链表l1的值。
//l2:
//指向第二个输入链表的当前节点。
//用于遍历并读取第二个链表l2的值。
//cur:
//指向结果链表的当前节点。
//当计算两个输入链表的节点之和时，你会在结果链表中创建一个新节点。
//cur指针用于跟踪和更新结果链表的末尾，这样你可以将新计算的值添加到结果链表的末尾。
//简单来说，l1和l2用于读取输入链表的值，而cur用于构建和更新结果链表。
//当执行cur = cur->next;时，你实际上是移动cur指针到结果链表的下一个节点。
//这确保下次你添加一个新节点时，它将被添加到结果链表的正确位置。

#include <stdio.h>
#include <iostream>

using namespace std;

class ListNode {
public:
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}

    // member function to print the list;
    void printList() const {
        const ListNode *current = this;
        while (current) {
            cout << current->val << "->";
            current = current->next;
        }
        cout << "nullptr" << endl;
    }
};

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        // newHead一直指向头结点，cur指向的是当前节点
        // 此处先创建了一个列表用于存储结果，并且把链表初始化节点的val值为 0
        ListNode *newHead = new ListNode(0);
        ListNode *cur = newHead;

        int carry = 0;

        while (l1 != nullptr || l2 != nullptr) {
            int x = (l1 != nullptr) ? l1->val : 0;
            int y = (l2 != nullptr) ? l2->val : 0;

            int sum = carry + x + y;
            // 取进位
            carry = sum / 10;
            //为结果链表创建一个新的链表节点，其值为sum的个位数。
            cur->next = new ListNode(sum % 10);
            // cur 移动指向下一个节点
            cur = cur->next;
            // 判断是否已经到了边界
            if (l1 != nullptr) l1 = l1->next;
            if (l2 != nullptr) l2 = l2->next;
        }
        if (carry > 0) {
            // 循环结束时carry依旧大于 0，说明有进位，此时把那个进位值添加到新的结点当中
            cur->next = new ListNode(carry);
        }
        // 实际的结果并不包含dummy node，如果不从真正节点开始返回则结果列表前面会多一个 0；
        // return newHead;
        ListNode *result = newHead->next;
        // 此时dummy node不再需要，因此应该释放由new开辟的空间
        delete newHead;
        return result;

    }
};

int main02() {
    ListNode l1(2);
    ListNode l2(5);
    Solution sol;
    l1.next = new ListNode(4);
    l1.next->next = new ListNode(3);
    l2.next = new ListNode(6);
    l2.next->next = new ListNode(4);
    ListNode *result = sol.addTwoNumbers(&l1, &l2);
    result->printList();
}
//使用哑节点（dummy node）在处理链表的问题中是一个常见的策略，它有几个主要优点：
//简化边界情况：在添加第一个节点到结果链表时，你不必单独处理这种情况。你可以始终假设在你当前的位置之前总是有一个节点。
//这简化了代码逻辑，减少了特殊情况的处理。
//提供一个统一的起始点：你不必担心结果链表的头节点是否已经设置或何时设置。哑节点为你提供了一个明确的、始终存在的起始点。
//避免额外的条件检查：在循环中，你可能经常检查链表是否为空或是否已经存在头节点等。使用哑节点可以减少这些检查，从而简化代码。
//代码整洁性和可读性：使用哑节点可以使代码更整洁和直观，这使得代码更容易理解和维护。
//以addTwoNumbers为例，如果没有哑节点，你需要写额外的代码来处理以下情况：
//当第一个节点被添加到结果链表时，你需要单独设置头节点。
//在循环中，你可能需要检查cur是否为空，或者结果链表的头节点是否已经被设置。
//使用哑节点，你可以避免上述复杂性，只需在循环结束后返回dummy->next即可。