#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
ListNode* removeElements(ListNode* head, int val) {
    ListNode* curNode = head;
    ListNode* curPrev = nullptr;
    while (curNode) {
        if (curNode->val != val) {
            curPrev = curNode;
            curNode = curNode->next;
        }
        else {
            // 相等时有两种情况 
            // 1. 头删  需要删结点  并 改 head
            if (head == curNode) {
                curNode = curNode->next;
                delete head;
                head = curNode;
            }
            // 2. 非头删，只需删结点   
            else {
                curPrev->next = curNode->next;
                delete curNode;
                curNode = curPrev->next;
            }
        }
    }
    return head;
}
int main() {
    ListNode* node1 = new ListNode(7);
    ListNode* node2 = new ListNode(7);
    ListNode* node3 = new ListNode(7);
    ListNode* node4 = new ListNode(7);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = nullptr;
    removeElements(node1, 7);

}