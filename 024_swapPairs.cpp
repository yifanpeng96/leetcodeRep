//24. 两两交换链表中的节点
//
//给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。
//
//你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。

//Tips:
//把要翻转的节点设为变量, 这样比较清晰

#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* swapPairs(ListNode* head) {
	if (head == nullptr) return nullptr;
	if (head->next == nullptr) return head;

	ListNode* preHead = new ListNode();
	preHead->next = head;

	ListNode* tmp = preHead;
	while (tmp->next != nullptr && tmp->next->next != nullptr) {
		ListNode* node1 = tmp->next;
		ListNode* node2 = tmp->next->next;
		tmp->next = node2;
		node1->next = node2->next;
		node2->next = node1;

		tmp = node1;
	}
	return preHead->next;
}

int main() {
	

	return 0;
}
