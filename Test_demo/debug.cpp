#include <iostream>
#include <functional>
#include <stdio.h>

using namespace std;


struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x = 0) : val(x), next(NULL) {}
};
ListNode* creatLiist() {
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(5);
    ListNode* node3 = new ListNode(2);
    ListNode* node4 = new ListNode(7);
    ListNode* node5 = new ListNode(3);
    ListNode* node6 = new ListNode(4);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;
    return node1;
}
class Partition {
public:
    ListNode* partition(ListNode* pHead, int x) {
        if (pHead == nullptr)
            return nullptr;
        ListNode* guardLess = new ListNode(0);
        ListNode* guardGreater = new ListNode(0);
        guardLess->next = guardGreater->next = nullptr;

        ListNode* lessTail = guardLess, * greaterTail = guardGreater;
        ListNode* curNode = pHead;
        while (curNode) {
            if (curNode->val < x) {
                lessTail->next = curNode;
                lessTail = lessTail->next;
            }
            else {
                greaterTail->next = curNode;
                greaterTail = greaterTail->next;
            }
            curNode = curNode->next;
        }
        // 链接两个链表
        lessTail->next = guardGreater->next;
        pHead = guardLess->next;
        delete guardGreater;
        delete guardLess;
        return pHead;
    }
};
int main() {
    Partition p1;
    p1.partition(creatLiist(), 5);
    return 0;
}