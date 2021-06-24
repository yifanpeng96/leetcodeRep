//61. 旋转链表
//
//给你一个链表的头节点 head ，旋转链表，将链表每个节点向右移动 k 个位置。

//Tips:
//可闭合成环, 最后断开

#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* rotateRight(ListNode* head, int k) {
    if (k == 0) return head;
    if (head == nullptr) return nullptr;

    //先遍历一次链表, 存储各节点位置
    vector <ListNode*> nodes;
    nodes.push_back(head);
    while (head->next != nullptr) {
        head = head->next;
        nodes.push_back(head);
    }

    int sz = nodes.size();
    //令 k 在 0 ~ sz - 1 的范围内
    k %= sz;
    if (k == 0) return nodes[0];

    ListNode* newHead = nodes[sz - k];
    ListNode* newTail = nodes[sz - k - 1];
    
    newTail->next = nullptr;
    head->next = nodes[0];//这里的head节点实际上为原末节点

    return newHead;
}

int main() {
	

	return 0;
}
